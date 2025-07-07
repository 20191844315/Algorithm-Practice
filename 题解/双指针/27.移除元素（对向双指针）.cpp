/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int left=0,right=n-1;
        while(left<=right){//双指针对撞,避免多次赋值
          
            if(nums[left]==val){
                nums[left]=nums[right];
                right--;
            }
            else {
                left++;
            }
        }
        return left;
    }
};
// @lc code=end

