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
        while(fast<n){
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

