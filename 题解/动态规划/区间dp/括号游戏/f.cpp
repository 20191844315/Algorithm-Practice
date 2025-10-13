#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

bool is_match(char a,char b){
    return (a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}');
}
int getscore(char c){
    if (c=='('||c==')'){
        return 1;
    }
    if (c=='['||c==']'){
        return 2;
    }
    if (c=='{'||c=='}'){
        return 3;
    }
    return 0;
}
int main(){
    string s;
    while(cin>>s){
        
        int n=s.length();
        
        //存比对手多得多少分
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
           dp[i][i]=getscore(s[i]);
            
        }
        //从长度开始遍历
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                int score;
                dp[i][j]=INT_MIN;
                if(is_match(s[i],s[j])){
                    score=2*getscore(s[i]);
                    dp[i][j]=max(dp[i][j],score-dp[i+1][j-1]);
                   
                }
                score=getscore(s[i]);
                dp[i][j]=max(dp[i][j],score-dp[i+1][j]);
                score=getscore(s[j]);
                dp[i][j]=max(dp[i][j],score-dp[i][j-1]);
            }
        }
       //此时玩家是小明
        int res=dp[0][n-1];
        if(res>0){
            cout<<"Xiao Ming Win"<<endl;
        }else if(res<0){
            cout<<"Xiao Hong Win"<<endl;
        }else cout <<"Draw"<<endl;
    }
    return 0;
}