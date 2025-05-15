// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem485.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int slow=0,fast=0;
        int maxc=0;
        while (fast<n)
        {
            if(nums[fast]==0){
                maxc=max(fast-slow,maxc);
                
                slow=fast+1;
            }
            fast++;

        }
        maxc=max(fast-slow,maxc); //当 nums[fast] == 0 时，才会计算当前连续1的长度
        return maxc;
        
    }
};
// @lc code=end

