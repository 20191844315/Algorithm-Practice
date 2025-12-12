
#include<bits/stdc++.h>
using namespace std;

inline double sqr(double x){return x*x;}

// 计算当前圆心坐标，首圆靠左墙，后续与已放圆相切
double getPosition(const vector<double>&r,const vector<int>&order,const vector<double>&site,double cur_r,int cur){
    if(cur==0)return cur_r;
    double pos=cur_r;
    for(int j=0;j<cur;++j){
        double prev_r=r[order[j]];
        pos=max(pos,site[j]+sqrt(sqr(prev_r+cur_r)-sqr(prev_r-cur_r)));
    }
    return pos;
}

// 剪枝：估算剩余最小长度，若已不优则直接返回
bool canBranch(const vector<double>&r,const vector<int>&order,const vector<double>&site,const vector<bool>&visited,int n,int cur,double right_edge,double ans){
    double min_r=1e10;
    for(int i=0;i<n;++i){
        if(!visited[i])min_r=min(min_r,r[i]);
    }
    double pos=getPosition(r,order,site,min_r,cur);
    double optimistic=max(right_edge,pos+min_r*(2*(n-cur)-1));
    return optimistic<ans;
}

// DFS枚举所有排列，site记录圆心坐标，order记录顺序
void dfs(const vector<double>&r,vector<int>&order,vector<double>&site,vector<bool>&visited,int n,int cur,double right_edge,double&ans){
    if(cur==n){
        ans=min(ans,right_edge);
        return;
    }
    if(!canBranch(r,order,site,visited,n,cur,right_edge,ans))return;
    for(int i=0;i<n;++i){
        if(visited[i])continue;
        double pos=getPosition(r,order,site,r[i],cur);
        double next_edge=max(right_edge,pos+r[i]);
        order[cur]=i;
        site[cur]=pos;
        visited[i]=true;
        dfs(r,order,site,visited,n,cur+1,next_edge,ans);
        visited[i]=false;
    }
}

int main(){
    int n;
    while(cin>>n){
        vector<double>r(n),site(n);
        vector<int>order(n);
        vector<bool>visited(n,0);
        double ans=1e20;
        for(int i=0;i<n;++i){
            cin>>r[i];
        }
        
        dfs(r,order,site,visited,n,0,0.0,ans);
        printf("%.7f\n",ans);
    }
    return 0;
}