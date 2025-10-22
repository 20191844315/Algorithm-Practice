#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct act{
    int s,t;
    act (int s=0,int t=0):s(s),t(t){}
};
bool cmp(const act &a,const act &b){
    return a.t<b.t;
}
//按结束时间从早到晚排序
int main(){
    int n;
    while(cin>>n){
        vector <act>acts(n);
        for(int i=0;i<n;i++){
            cin>>acts[i].s>>acts[i].t;
        }
        sort(acts.begin(),acts.end(),cmp);
        int sum=0,last=-1;
        for(act a:acts){
            if(a.s>=last){
                sum++;
                last=a.t;
            }
        }
        cout<<sum<<endl;

    }
    return 0;

}