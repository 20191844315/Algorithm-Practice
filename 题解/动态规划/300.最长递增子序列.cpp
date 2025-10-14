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
    //穷举
    int lengthOfLIS1(vector<int>& nums) {
        int n=nums.size();
        
        int maxres=1;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                    if(nums[i]>nums[j]){
                        dp[i]=max(dp[j]+1,dp[i]);
                    }
            }
     
            if(dp[i]>maxres){
                maxres=dp[i];
            }
        }
        return maxres;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //dp[i]存入的是长度为i的递增子序列中，最小的结束元素
        vector<int>dp;
         for(int i=0;i<n;i++){
            //二分查找在dp中第一个>=a[i]小的元素
            auto it =lower_bound(dp.begin(),dp.end(),a[i]);
            if(it==dp.end()){
                dp.push_back(a[i]);
            }else{
                *it = a[i];
            }
        }
        
        cout<<dp.size()<<endl;
    }
};
// @lc code=end

