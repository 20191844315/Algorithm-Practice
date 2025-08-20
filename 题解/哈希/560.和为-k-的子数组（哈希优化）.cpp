/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum1(vector<int>& nums, int k) {
        int ans=0;
        vector<int> sums;
        int n=nums.size();
        sums.resize(n+1);
        sums[0]=0;
        for(int i=0;i<n;i++){
            sums[i+1]=nums[i]+sums[i];
        }
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(sums[j]-sums[i]==k){
                    ans++;
                }
            }
        }
        return ans;
    }
    /*
    用哈希表优化,遇到枚举有多少个 s[j]−s[i]=k的时候,
    改为遍历在遇到j后，往前找满足条件的i

    */
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int sum=0;
        unordered_map<int, int> cnt;
        for(int i=0;i<nums.size();i++){
            cnt[sum]++;
            sum+=nums[i];
            
            if(cnt.contains(sum-k)){
                ans+=cnt[sum-k];
            }
            
        }
        return ans;
    }
};
// @lc code=end

