#include<bits/stdc++.h>

using namespace std;
void dfs(int cur ,int sum,int r,const vector<int> &nums, vector<int> &res, vector<vector<int>> &ans){
    if(sum==r){
        // reverse(res.begin(), res.end());
        ans.push_back(res);
        return;
    }
    if(cur==nums.size()){
        return;
    }
    
        res[cur]=1;
        dfs(cur+1,sum+1,r,nums,res,ans);
        res[cur]=0;
        dfs(cur+1,sum,r,nums,res,ans);
    
    return;
}

int main(){
    int n,r;
    while(cin>>n>>r){
        vector<int> nums(n);
        vector<int> res(n,0);
         vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        dfs(0,0,r,nums,res,ans);

        reverse(ans.begin(), ans.end());
        // 若需去重（nums 含相同值时可能出现相同序列），可启用：
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for(const auto& res : ans){
            for(int i=n-1 ;i>=0;i--){
                if(res[i]==1){
                    cout<<nums[n-i-1]<<" ";
                }
            }
            cout <<endl;
        }
    }
    return 0;
}