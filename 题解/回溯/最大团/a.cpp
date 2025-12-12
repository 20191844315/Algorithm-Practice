#include<bits/stdc++.h>

using namespace std;
//判断cur是否可以加入当前团中
bool check(int cur,int n,const vector<vector<int>>&graph,vector<int>&visited){
    
    for(int i=0;i<n;i++){
        if(visited[i]==1){
            bool sign=false;;
            for(auto neighbor:graph[i]){
                if(neighbor==cur){
                    sign=true;
                }
            }
            if(sign==false){
                return sign;
            }
        }
    }
    return true;
}

void dfs(int cur,int n,int &max_res,int cur_res,const vector<vector<int>>&graph,vector<int>&visited){
    if(cur==n){
        if(cur_res>max_res){
            max_res=cur_res;
        }
        return;
    }
    //cut
    if(max_res!=-1){
        int last=n-cur+1;
        if(cur_res+last<=max_res){
            return;
        }
    }

    if(check(cur,n,graph,visited)){
        visited[cur]=1;
        dfs(cur+1,n,max_res,cur_res+1,graph,visited);
        visited[cur]=0;
        dfs(cur+1,n,max_res,cur_res,graph,visited);
    }else{
        dfs(cur+1,n,max_res,cur_res,graph,visited);
    }
    return;


}
int main(){
    int n,m;
    while(cin>>n>>m){
        vector<vector<int>>graph(n);
        vector<int>visited(n,0);
        int max_res=-1;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);

        }
        dfs(0,n,max_res,0,graph,visited);
        cout<<max_res<<endl;
    }
    return 0;
}