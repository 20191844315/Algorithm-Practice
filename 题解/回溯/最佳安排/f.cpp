#include<bits/stdc++.h>
using namespace std;
//cur当前执行任务的机器,best_t当前最小的时间，cur_t当前的时间
void dfs_machine(int cur,int n,int &best_t,int cur_t,const vector<vector<int>> &a, vector<bool> &used){
    if(cur==n){
        if(best_t==-1)best_t=cur_t;
        best_t=min(best_t,cur_t);
        return ;
    }
    //剪枝函数
    if(best_t!=-1){
        if(cur_t>=best_t)return;
    }
    //对于每个任务i
    for(int i=0;i<n;i++){
        if(used[i])continue;
        used[i]=true;
        dfs_machine(cur+1,n,best_t,cur_t+a[cur][i],a,used);
        used[i]=false;
    }
    return;
}
int main(){
    int n;
    while(cin>>n){
        vector<vector<int>> a(n,vector<int>(n));
        vector<bool> used(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        int best_t=-1;
        dfs_machine(0,n,best_t,0,a,used);
        cout<<best_t;
    }

    return 0;
}