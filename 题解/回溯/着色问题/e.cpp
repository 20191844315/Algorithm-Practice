#include<bits/stdc++.h>
using namespace std;
//用邻接表时间复杂度更好，按度数降序，先染色度数大的点，剪纸效果更好。
//检查当前节点有哪些颜色不能用
vector<bool> check_g(int cur, const vector<vector<int>> &graph, const vector<int> &color, int m){
    vector<bool> nocolor(m+1, false);
    int n = (int)graph.size();
    for(int v=0;v<n;v++){
        if(graph[cur][v]&&color[v]!=0){
            int c=color[v];
            if(c>=1&&c<=m){
                nocolor[c]=true;
            }
        }
    }
    
    return nocolor;
}

void dfs(int cur,int m,int n,int &ans,const vector<vector<int>> &graph, vector<int> &color){
    if(cur==n){
        ans++;
        return ;
    }
    vector<bool> nocolor = check_g(cur, graph, color, m);
    
    for(int i=1;i<m+1;i++){
        if(nocolor[i]){
            continue;
        }
        color[cur]=i;
        dfs(cur+1,m,n,ans,graph,color);
        color[cur]=0;
    }
    return;
}
int main(){
    int n,m,q;
    while(cin>>n>>m>>q){
        vector<vector<int>> graph(n,vector<int>(n,0));
        vector<int>color(n,0);//每个节点存储的颜色
        for(int i=0;i<q;i++){
            int j,k;
            cin>>j>>k;
            graph[j-1][k-1]=1;
            graph[k-1][j-1]=1;
        }
        int ans = 0;
        dfs(0,m,n,ans,graph,color);
        cout<<ans<<endl;
    }
}