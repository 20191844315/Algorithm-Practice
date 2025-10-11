#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//默认构造函数
struct cube{
    int l=0,w=0,h=0;
    cube()=default;
    cube(int l,int w,int h):l(l),w(w),h(h){}
};
//面积小不一定代表可以放在上面
bool cmp_cube(const cube &a,const cube &b){
    return a.l*a.w>b.l*b.w;
}
bool cmp_cube_n(const cube &a, const cube &b) {
    if (a.l != b.l) return a.l > b.l;
    return a.w > b.w;
}

int main(){
    int n;
    while(cin>>n){
        long long res=-1;
        vector<cube>cubes;
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            //每个选择方式成为一个独立的箱子
            cubes.push_back(cube(max(a,b),min(a,b),c));
            cubes.push_back(cube(max(a,c),min(a,c),b));
            cubes.push_back(cube(max(c,b),min(c,b),a));                        
        }
        //按面积从大到小排序
        sort(cubes.begin(),cubes.end(),cmp_cube_n);
        //构建邻接表,稀疏矩阵,O(n^2)
        vector<vector<int>> graph(cubes.size());
        for(int i=0;i<cubes.size();i++){
            for(int j=i+1;j<cubes.size();j++){//只考虑面积更小的箱子
                if(cubes[i].l>cubes[j].l&&cubes[i].w>cubes[j].w){
                    graph[i].push_back(j);
                }

            }
        }
        //动态规划,存储以i为最后一个箱子的最大高度；
        vector<long long>dp(cubes.size(),-1);
        // 初始化每个箱子的高度
        for(int i=0;i<cubes.size();i++){
            dp[i]=cubes[i].h;
        }
        
        for(int i=0;i<cubes.size();i++){
            for(int j:graph[i]){
                dp[j]=max(dp[j],dp[i]+cubes[j].h);
            }
        }
        for(int i=0;i<cubes.size();i++){
            res=max(res,dp[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}
