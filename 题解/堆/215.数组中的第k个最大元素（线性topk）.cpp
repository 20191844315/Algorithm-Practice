/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
int quickget(vector<int>&a,int left, int right,int k){
    if(left==right-1){
        return a[left];
    }
    
    int l=left,r=right-1;
    int p=a[l];
    while(l<r){
        while(l<r &&a[r]>=p){
            r--;
        }
        a[l]=a[r];

        while(l<r &&a[l]<=p){
            l++;
        }
        a[r]=a[l]; 
    }
    a[l]=p;//填上一行代码的后一个数

    if((l-left)==k-1){
        return a[l];
    }else if((l-left)<k-1){
        return quickget(a,l+1,right,k-(l-left)-1);
    }else{
        return quickget(a,left,l,k);
    }

}

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + (n - k), nums.end());

        //return nums[n - k];
        return quickget(nums,0,n,k);
    }
};
// @lc code=end

