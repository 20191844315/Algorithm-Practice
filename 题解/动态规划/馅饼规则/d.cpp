#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<long long> pie(n);
        for (int i=0;i<n;i++){
            cin>>pie[i];
        }
        vector<vector<pair<long long, long long>>> dp(n + 1, vector<pair<long long, long long>>(2, {0, 0}));
        for(int i=n-1;i>=0;i--){
            //此时a在做决策
            //给出令牌，所以下一状态是dp[i+1][1]
            long long a_eat_a_pie=dp[i+1][1].first+pie[i];//a选择自己吃时，a吃的派的数量
            long long a_eat_b_pie=dp[i+1][1].second;//a选择自己吃时，b吃的派的数量
            //保留令牌，所以下一状态是dp[i+1][0]
            long long a_noeat_a_pie=dp[i+1][0].first;//a选择给b吃时，a吃的派的数量
            long long a_noeat_b_pie=dp[i+1][0].second+pie[i];//a选择给b吃时，b吃的派的数量
            // Alice选择对自己更有利的选项（比较自己得到的切片数）
            if (a_eat_a_pie>=a_noeat_a_pie) {
                dp[i][0] = {a_eat_a_pie,a_eat_b_pie};
            } else {
                dp[i][0] = {a_noeat_a_pie,a_noeat_b_pie};
            }
            //此时b在做决策
            //给出令牌，所以下一状态是dp[i+1][0]
            long long b_eat_a_pie=dp[i+1][0].first;//b选择自己吃时，a吃的派的数量
            long long b_eat_b_pie=dp[i+1][0].second+pie[i];//b选择自己吃时，b吃的派的数量
            //保留令牌，所以下一状态是dp[i+1][1]
            long long b_noeat_a_pie=dp[i+1][1].first+pie[i];//b选择给a吃时，a吃的派的数量
            long long b_noeat_b_pie=dp[i+1][1].second;//b选择给a吃时，b吃的派的数量
            // Alice选择对自己更有利的选项（比较自己得到的切片数）
            if (b_eat_b_pie>=b_noeat_b_pie) {
                dp[i][1] = {b_eat_a_pie,b_eat_b_pie};
            } else {
                dp[i][1] = {b_noeat_a_pie,b_noeat_b_pie};
            }
        }   
        cout<<dp[0][1].first<<" "<<dp[0][1].second<<endl;
    }
    return 0;
}