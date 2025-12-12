#include<bits/stdc++.h>
using namespace std;
int check(const vector<int>&minv,vector<int>&visited){
    int sum=0;
    for(int i=0;i<minv.size();i++){
        if(visited[i]==0){
            sum+=minv[i];
        }
    }
    return sum;
}
void dfs(int cur,int n,int last,int &best_res,int cur_res,const vector<vector<int>>&graph,vector<int>&visited,const vector<int>&minv){
    if(cur==n){
        cur_res+=graph[last][0];
        if(best_res==-1){
            best_res=cur_res;
        }else{
            best_res=min(best_res,cur_res);
        }
    }

    //cut
    if(best_res!=-1){
        if(cur_res+check(minv,visited)>=best_res)return;
    }

    //不用查找0点
    for(int i=1;i<n;i++){
        //忘记检查visited
        if(visited[i]==1)continue;
        visited[i]=1;
        dfs(cur+1,n,i,best_res,cur_res+graph[last][i],graph,visited,minv);
        visited[i]=0;
    }
    return;
}
int main(){
    int n;
    while(cin>>n){
        int m=n*(n-1)/2;
        vector<vector<int>>graph(n,vector<int>(n,0));
        vector<int>minv(n,INT_MAX);
        vector<int>visited(n,0);
        int best_res=-1;
        for(int i=0;i<m;i++){
            int a,b,v;
            cin>>a>>b>>v;
            graph[a-1][b-1]=v;
            graph[b-1][a-1]=v;
            minv[a-1]=min(v,minv[a-1]);
            minv[b-1]=min(v,minv[b-1]);

        }
        
        dfs(1,n,0,best_res,0,graph,visited,minv);
        //忘记输出
        cout<<best_res<<endl;
    }
    return 0;
}