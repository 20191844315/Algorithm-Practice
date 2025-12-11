#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void dfs(int cur,const vector<int> &nums, vector<int> &res,vector<bool> &visit){
    //如果遍历完，输出序列res
    if(cur==nums.size()){
        for(int i=0;i<nums.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<nums.size();i++){//遍历找下一个未访问过的元素
        if(visit[i]){
            continue;
        }
        //
        if(i>0&&res[i]==res[i-1]&&visit[i-1])continue;
        visit[i]=true;
        res[cur]=nums[i];
        dfs(cur+1,nums,res,visit);
        visit[i]=false;


    }
}
int main(){
    int n;
    while(cin>>n){
        vector<int> nums(n);
        vector<int> res(n);
        vector<bool> visit(n,false);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        dfs(0,nums,res,visit);
    }
    return 0;
}