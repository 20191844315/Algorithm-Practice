#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    while(cin>>t){
        while(t--){
            long long a,b,p,ans=1;
            cin>>a>>b>>p;
           
            while(b>0){
                if(b%2==1){
                    ans=(ans*a)%p;
                    b--;
                    
                }
                a=(a*a)%p;
                
                b/=2;

            }
            cout<<ans%p<<endl;
            

        }
    }
}