#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,b;
    while(cin>>n>>b){
        vector<int>w(n);
        vector<int>v(n);
        vector<int>dp(b+1,0);
        for(int i=0;i<n;i++){
            cin>>w[i]>>v[i];
        }
        for(int i=0;i<n;i++){
            for(int j=b;j>=w[i];j--){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout<<dp[b]<<endl;
    }
    return 0;
}