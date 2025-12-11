#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll INF=(ll)9e18;

// ----------- 全局变量 -------------
int n,K;
vector<int> a;       // 输入数组（1-index）
vector<ll> freq;     // freq[x]=当前窗口内 x 出现频次
ll curCost=0;      // 当前窗口的代价（所有重复元素的成对出现数）
int curL=1,curR=0;// 当前窗口为 [curL,curR]，初始为空

// ----------- 维护区间成本的函数（MO 算法的增量方式） -------------

// 在右端增加一个元素 a[idx]
inline void addRight(int idx){
    int x=a[idx];
    curCost+=freq[x];// 加上已有 freq[x] 个相同的
    freq[x]++;
}

// 在右端删除一个元素 a[idx]
inline void removeRight(int idx){
    int x=a[idx];
    freq[x]--;
    curCost-=freq[x];
}

// 在左端增加一个元素 a[idx]
inline void addLeft(int idx){
    int x=a[idx];
    curCost+=freq[x];
    freq[x]++;
}

// 在左端删除一个元素 a[idx]
inline void removeLeft(int idx){
    int x=a[idx];
    freq[x]--;
    curCost-=freq[x];
}

// ---------- 将当前窗口移动到目标区间 [L,R] ----------
void moveTo(int L,int R){
    // 扩展左端
    while(curL>L)addLeft(--curL);
    // 扩展右端
    while(curR<R)addRight(++curR);
    // 收缩左端
    while(curL<L)removeLeft(curL++);
    // 收缩右端
    while(curR>R)removeRight(curR--);
}

/*
 ---------------------------------------------------------
 令 dp[t][i] 表示：把数组前 i 个元素分成 t 段 能达到的 最小总代价（cost 的定义见你代码，是区间内相同元素成对出现的次数之和）。
把前 i 个元素分成 t 段，考虑最后一段的起点位置：如果最后一段是 [j+1, i]（注意 j < i），那么前 j 个元素就需要被分成 t-1 段，其代价为 dp[t-1][j]。最后一段的代价是 cost(j+1, i)。
因此对所有可能的 j（0 到 i-1）枚举，取最小值：
 使用分治优化计算：
 dpCur[mid]=min(dpPrev[j](j<mid)+cost(j+1,mid)

 ---------------------------------------------------------
*/
void solve_dc(int L,int R,int optL,int optR,const vector<ll> &dpPrev,vector<ll> &dpCur){
    //我要计算 dpCur[L], dpCur[L+1], …, dpCur[R] 这些值
    //optL, optR —— 当前区间内的最优 j 的搜索范围
    if(L>R)return;

    int mid=(L+R)>>1;
    ll bestdp=INF;//最优的dp值
    int bestK=-1;

    // j 必须满足 j<mid，否则 j+1>mid 区间为空
    int start=max(optL,0);
    int end=min(optR,mid-1);

    for(int j=start;j<=end;j++){
        // 在[optl,optr]穷举j
        moveTo(j+1,mid);
        ll val=dpPrev[j]+curCost;
        if(val<bestdp){
            bestdp=val;
            bestK=j;
        }
    }
    
    dpCur[mid]=bestdp;
    if(L==R)return;

    /*
    求 mid 的 dpCur[mid] → 得到最优断点 bestK
    左边 [L..mid-1]，最优断点不会大于 bestK → j ∈ [optL..bestK]
    右边 [mid+1..R]，最优断点不会小于 bestK → j ∈ [bestK..optR]
    递归下去，整个 dpCur[i] 都被计算完，但 j 的枚举范围越来越小 → 提高效率
    */
    solve_dc(L,mid-1,optL,bestK,dpPrev,dpCur);
    solve_dc(mid+1,R,bestK,optR,dpPrev,dpCur);
}

int main(){
    cin>>n>>K;
    a.assign(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];

    // 因为值域 ≤ n，所以 freq 大小 n 即可
    freq.assign(n+1,0);

    // dpPrev=dp[t-1][*]，dpCur=dp[t][*]
    vector<ll> dpPrev(n+1,INF),dpCur(n+1,INF);
    dpPrev[0]=0; // 0 个元素分成 0 段的代价是 0

    // 进行 K 轮 DP
    for(int t=1;t<=K;++t){

        //初始化
        //每一层都要把窗口恢复成空的，避免上一层残留
        fill(freq.begin(),freq.end(),0);
        curCost=0;
        curL=1;
        curR=0;
        fill(dpCur.begin(),dpCur.end(),INF);

        // 分治优化求 dp[t][1..n]
        solve_dc(1,n,0,n-1,dpPrev,dpCur);

        dpPrev.swap(dpCur);// 下一层 DP 用
    }

    // dp[K][n] 即答案
    cout << dpPrev[n] << "\n";
    return 0;
}
