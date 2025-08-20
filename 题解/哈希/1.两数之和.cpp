/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

/*哈希法就是存储键值对，且两者绑定，
本质是如何通过一个键值来映射到目的元素，
然后通过amp[key]直接获得前一个元素

*/
class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
       map<int,int>map;
       int n=nums.size();
       for(int i=0;i<n;i++){
            int p=target-nums[i];
            if(map.count(p)){
                return {i,map[p]};
            }
            map[nums[i]]=i;
       } 
       return {};
    }
    
};
// @lc code=end

