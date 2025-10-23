/*
 * @lc app=leetcode.cn id=1589 lang=cpp
 *
 * [1589] 所有排列中的最大和
 */

// @lc code=start
class Solution {
public:
    const int mod=1e9+7;
    static bool cmp(int a,int b){
        return a>b;
    }
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int ans=0;
        //大小需要n+1，但其实第n+1的元素不参与后续运算
        vector<int>diff(nums.size()+1,0);
        vector<int>fre(nums.size(),0);
        for (auto r:requests){
            diff[r[0]]+=1;
            diff[r[1]+1]-=1;
        }
        fre[0]=diff[0];
        for(int i=1;i<nums.size();i++){
            fre[i]=fre[i-1]+diff[i];
        }
        sort(nums.begin(), nums.end(),cmp);
        sort(fre.begin(),fre.end(),cmp);
        for(int i=0;i<nums.size();i++){
            ans=(ans+1ll*nums[i]*fre[i])%mod;
        }
        return ans;
    }
};
// @lc code=end

