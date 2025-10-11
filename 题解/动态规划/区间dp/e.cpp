#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

bool is_match(char a,char b){
    return (a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}');
}
int main(){
    string s;
    while(cin>>s){
        
        int n=s.length();
        if(n==0){
            cout<<"SZTU_WOD YYDS!"<<endl;
            continue;;
        }
        //初始化dp，默认值为0，自己为1
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                dp[i][j]=INT_MAX;
                if(is_match(s[i],s[j])){
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                }

                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                
            }
        }
        if(dp[0][n-1]==0){
            cout<<"SZTU_WOD YYDS!"<<endl;
        }else{
            cout<<dp[0][n-1]<<endl;
        }
    }
    return 0;
}