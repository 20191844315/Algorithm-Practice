// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int fast=1,slow=1;
        if(n==0){
            return 0;
        }
        while(fast<n){//slow和fast在逻辑上分成两个数组，不需要将fast从后往前
            if(nums[fast]!=nums[fast-1]){
                nums[slow]=nums[fast];
                ++slow;

            }
            ++fast;
        }
        return slow;
    }
};
// @lc code=end

