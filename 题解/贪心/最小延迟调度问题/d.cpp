#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

struct act{
    int t,d,w;
    act(int t=0,int d=0,int w=0):t(t),d(d),w(w){}
};
bool cmp(const act &a,const act &b){
    return a.d<b.d;
}
//按结束时间从早到晚排序
int main(){
    int T;
    while(cin>>T){
        while(T--){
            int n;
            while(cin>>n){
                vector <act>acts(n);
                for(int i=0;i<n;i++){
                    cin>>acts[i].t>>acts[i].d;
                
                }
                sort(acts.begin(),acts.end(),cmp);
                int t=0,ans=0;
                for(act a:acts){
                    t+=a.t;
                    ans=max(ans,t-a.d);
                }

                cout<<ans<<endl;
            }
        }

    }
    return 0;

}