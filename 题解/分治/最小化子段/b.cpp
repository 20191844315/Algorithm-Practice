#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = (ll)9e18;

// ----------- 全局变量 -------------
int n, K;
vector<int> a;        // 输入数组（1-index）
vector<ll> freq;      // freq[x] = 当前窗口内 x 出现频次
ll curCost = 0;       // 当前窗口的代价（所有重复元素的成对出现数）
int curL = 1, curR = 0; // 当前窗口为 [curL, curR]，初始为空

// ----------- 维护区间成本的函数（MO 算法的增量方式） -------------

// 在右端增加一个元素 a[idx]
inline void addRight(int idx) {
    int x = a[idx];
    curCost += freq[x]; // 加上已有 freq[x] 个相同的
    freq[x]++;
}

// 在右端删除一个元素 a[idx]
inline void removeRight(int idx) {
    int x = a[idx];
    freq[x]--;
    curCost -= freq[x];
}

// 在左端增加一个元素 a[idx]
inline void addLeft(int idx) {
    int x = a[idx];
    curCost += freq[x];
    freq[x]++;
}

// 在左端删除一个元素 a[idx]
inline void removeLeft(int idx) {
    int x = a[idx];
    freq[x]--;
    curCost -= freq[x];
}

// ---------- 将当前窗口移动到目标区间 [L,R] ----------
void moveTo(int L, int R) {
    // 扩展左端
    while (curL > L) addLeft(--curL);
    // 扩展右端
    while (curR < R) addRight(++curR);
    // 收缩左端
    while (curL < L) removeLeft(curL++);
    // 收缩右端
    while (curR > R) removeRight(curR--);
}

/*
 ---------------------------------------------------------
 使用分治优化计算：
 dpCur[mid] = min_{j in [optL, optR]} dpPrev[j] + cost(j+1, mid)
 其中 cost(L,R) 由 moveTo(L,R) 动态维护
 ---------------------------------------------------------
*/
void solve_dc(int L, int R, int optL, int optR,
              const vector<ll> &dpPrev, vector<ll> &dpCur)
{
    if (L > R) return;
    int mid = (L + R) >> 1;

    ll bestVal = INF;
    int bestK = -1;

    // j 必须满足 j < mid，否则 j+1 > mid 区间为空
    int start = max(optL, 0);
    int end   = min(optR, mid - 1);

    for (int j = start; j <= end; ++j) {
        // 窗口移动到区间 [j+1, mid]
        moveTo(j + 1, mid);

        ll val = dpPrev[j] + curCost;
        if (val < bestVal) {
            bestVal = val;
            bestK = j;
        }
    }

    dpCur[mid] = bestVal;

    if (L == R) return;

    // 在最优决策点 bestK 左右递归
    solve_dc(L, mid - 1, optL, bestK, dpPrev, dpCur);
    solve_dc(mid + 1, R, bestK, optR, dpPrev, dpCur);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> K;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // 因为值域 ≤ n，所以 freq 大小 n 即可
    freq.assign(n + 1, 0);

    // dpPrev = dp[t-1][*]，dpCur = dp[t][*]
    vector<ll> dpPrev(n + 1, INF), dpCur(n + 1, INF);
    dpPrev[0] = 0;  // 0 个元素分成 0 段的代价是 0

    // 进行 K 轮 DP
    for (int t = 1; t <= K; ++t) {

        // 每一层都要把窗口恢复成空的，避免上一层残留
        fill(freq.begin(), freq.end(), 0);
        curCost = 0;
        curL = 1;
        curR = 0;

        fill(dpCur.begin(), dpCur.end(), INF);

        // 分治优化求 dp[t][1..n]
        solve_dc(1, n, 0, n - 1, dpPrev, dpCur);

        dpPrev.swap(dpCur); // 下一层 DP 用
    }

    // dp[K][n] 即答案
    cout << dpPrev[n] << "\n";
    return 0;
}
