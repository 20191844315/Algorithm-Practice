#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
    while(cin>>n>>m){
        if(n==0)break;
        vector<vector<int>>g(n,vector<int>(m,0));
        vector<vector<int>>dp(n,vector<int>(m,0));
        int maxe=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
                if(i==0&&g[i][j]==1){
                    dp[i][j]=1;
                    maxe=max(maxe,dp[i][j]);
                }
                if(j==0&&g[i][j]==1){
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
               if(g[i][j]==1){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1])+1;
                maxe=max(maxe,dp[i][j]);
               }
            }
        }
        cout<<maxe*maxe<<endl;

    }
    return 0;
}