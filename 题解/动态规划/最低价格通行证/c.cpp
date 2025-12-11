#include<bits/stdc++.h>
using namespace std;
vector<int> costs(3);
vector<int> days;
vector<int> dp(368,0);
int n;
int main(){
    while(cin>>costs[0]>>costs[1]>>costs[2]){
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            days.push_back(temp);
        }
        sort(days.begin(),days.end());
        for(int i:days){
            dp[i]=dp[i-1]+costs[0];
            dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]); // 7 day
            dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]); // 
            // if(i>=7)dp[i]=min(dp[i-7]+costs[1],dp[i]);
            // if(i>=30)dp[i]=min(dp[i-30]+costs[2],dp[i]);
            for(int j=i+1;j<368;j++){
                dp[j]=dp[i];
            }
        }
       cout<<dp[365]<<endl;

    }
}