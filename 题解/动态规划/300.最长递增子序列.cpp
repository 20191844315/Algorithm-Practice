// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem300.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        int maxres=1;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                    if(nums[i]>nums[j]){
                        dp[i]=max(dp[j]+1,dp[i]);
                    }
            }
            /*
            if(i>0&&nums[i-1]>=nums[i]){
                dp[i]=1;
                
            }else if(i>0&&nums[i]>nums[i-1]){
                for(int j=0;j<i;j++){
                    if(nums[i]>nums[j]){
                        dp[i]=max(dp[j]+1,dp[i]);
                    }
                }
            }
            */
            if(dp[i]>maxres){
                maxres=dp[i];
            }
        }
        return maxres;
    }
};
// @lc code=end

