#include<bits/stdc++.h>
using namespace std;
char sc[2010];
bool is_p(string s,int l,int r){
    // int n=s.length();
    // int l=0,r=n-1;
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;

}
bool is_ans(string s){
    int n=s.length();
    for(int i=0;i<n-2;i++){
        if(is_p(s,0,i)){
            for(int j=i+1;j<n-1;j++){
                if(is_p(s,i+1,j)&&is_p(s,j+1,n-1)){
                    return true;
                }
            }
        }
            
    }
    return false;
    
}
/*
%[集合]   // 只读取集合中的字符
%[^集合]  // 读取直到遇到集合中的任意字符（即不读取集合中的字符）
// 关键修改1：在格式字符串前加空格，跳过空白字符（包括换行）,保证循环读入
*/
int main(){
    while(scanf(" s = \"%[^\"]\"",sc)==1){
        string s=sc;
        if(is_ans(s)){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }

    }
}