#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    while(cin>>n>>m){
        vector<long long>nums(n);
        
        for(long long i=0;i<n;i++){
            cin>>nums[i];
        }
        
        //分块
        long long blk_size=sqrt(n)+1;
        long long blk_num=(n+blk_size-1)/blk_size;

        vector<long long>sum(blk_num,0);
        vector<long long>add(blk_num,0);
        vector<long long> L(blk_num), R(blk_num);

        //初始化分块和
        for(long long i=0;i<n;i++){
            long long blk_id=i/blk_size;
            sum[blk_id]+=nums[i];
            
        }
        for(long long i=0;i<blk_num;i++) {
            L[i]=i*blk_size;
            R[i]=min(n-1,(i+1)*blk_size-1);
        }
        while(m--){
            long long op;
            cin>>op;
            if (op==1){//区间加
                long long l,r,v;
                cin>>l>>r>>v;
                long long l_id=l/blk_size;
                long long r_id=r/blk_size;
                if(r_id-l_id<=1){//同一块里,或相邻两块
                   for(long long j=l;j<=r;j++){
                        nums[j]+=v;
                        sum[j/blk_size]+=v;
                    }
                    
                }else{
                    for(long long j=l;j<(l_id+1)*blk_size;j++){
                        nums[j]+=v;
                        sum[j/blk_size]+=v;
                    }
                    for(long long j=l_id+1;j<r_id;j++){
                        sum[j]+=v*(R[j]-L[j]+1);
                        add[j]+=v;
                    }
                    for(long long j=(r_id)*blk_size;j<=r;j++){
                        nums[j]+=v;
                        sum[j/blk_size]+=v;
                    }
                }
            }else{
                long long l,r;
                cin>>l>>r;
                long long ans=0;
                long long l_id=l/blk_size;
                long long r_id=r/blk_size;
                if(r_id==l_id){//同一块里,或相邻两块
                   for(long long j=l;j<=r;j++){
                       ans+=nums[j]+add[j/blk_size];
                    }
                    
                }else{
                    for(long long j=l;j<(l_id+1)*blk_size;j++){
                        ans+=nums[j]+add[l_id];
                    }
                    for(long long j=l_id+1;j<r_id;j++){
                        ans+=sum[j];
                    }
                    for(long long j=(r_id)*blk_size;j<=r;j++){
                        ans+=nums[j]+add[r_id];
                    }
                }
                cout<<ans<<endl;
            }
        }
        
        

    }
}