#include<bits/stdc++.h>
using namespace std;
using ll =long long;

class Fenwick{
    vector<ll> tree;
    ll n;
    ll lowbit(ll x){
        return x&-x;
    } 

public:
    Fenwick(ll size):n(size),tree(size+1,0){}

    void update(ll idx){//更新：在 idx 处加 1
        while(idx<=n){
            tree[idx]+=1;
            idx+=lowbit(idx);
        }
    }
    // 查询：前缀和 [1..idx]
    ll query(ll idx){
        ll sum=0;
        while(idx>0){
            sum+=tree[idx];
            idx-=lowbit(idx);
        }
        return sum;
    }
    // 查询区间 [l, r] 的和
    ll rangequery(ll l,ll r){
        if(l>r)return 0;
        return query(r)-query(l-1);
    }
};

int main(){
    ll n;
    while(cin>>n){
       vector<ll> nums(n);
       for(long long i=0;i<n;i++){
            cin>>nums[i];
        }
        /*
        散化就是把一组范围很大的数据，映射到从1开始的连续整数上，同时保持原来的大小关系不变。就像给学生按成绩排名：
        原来成绩：95, 87, 95, 100, 87
        排名：2, 1, 2, 3, 1
        */
        //离散化,去重
        vector<ll> sortn=nums;
        sort(sortn.begin(),sortn.end());
        sortn.erase(unique(sortn.begin(),sortn.end()),sortn.end());
        //映射排名
        vector<ll> rank(n);
        for(long long i=0;i<n;i++){
            rank[i]=lower_bound(sortn.begin(),sortn.end(),nums[i])-sortn.begin()+1;
        }

        Fenwick fenwick(sortn.size());
        ll ans=0;
        for (long long i=0;i<n;i++){
            ll x=rank[i];
            ans+=fenwick.rangequery(x+1,sortn.size());
            fenwick.update(x);
        }
        cout<<ans<<endl;
    }
    return 0;
}