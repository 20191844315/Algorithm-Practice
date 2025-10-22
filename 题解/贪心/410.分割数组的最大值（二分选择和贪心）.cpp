/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    bool check(const vector<int>&nums,int x,int k){
        long long sum=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>x){
                cnt++;
                sum=nums[i];
            }else{
                sum+=nums[i];
            }
        }
        return cnt<=k;
    }
    vector<int> find_pos(const vector<int>& nums,int x){
        vector<int>pos;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>x){
                pos.push_back(i);
                sum=nums[i];
            }else{
                sum+=nums[i];
            }
        }
        return pos;
    }

    int splitArray(vector<int>& nums, int k) {
            //初始化left是最大的nums[i]，right为nums的和
    long long left=0,right=0;
    for(int i=0;i<nums.size();i++){
        right+=nums[i];
        if(left<nums[i]){
            left=nums[i];
        }
    }

    while(left<right){
        long long mid=(left+right)>>1;
        if(check(nums,mid,k)){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
    }
};
// @lc code=end

