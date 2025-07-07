// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans ;
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            //temp在找不到解时不能有效的收敛计算,造成超时，本质还是O(n3)
            // for(int j=i+1;j<n-1;j++){
            //     if(j>i+1&&nums[j]==nums[j-1]){
            //         continue;
            //      }
            //     int temp=n-1;
            //     for(int k=temp;k>j;k--){
            //         if(nums[i]+nums[j]+nums[k]==0){
            //              ans.push_back({nums[i],nums[j],nums[k]});
            //             temp=k-1;
            //             break;
            //         }else if(nums[i]+nums[j]+nums[k]<0){
            //              break;
            //         }/
            //     }
            //}
            
            int k=n-1,tar=nums[i];
            
            for(int j=i+1;j<k;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                continue;
                }
                while(j<k&&nums[j]+nums[k]>-tar){
                    k--;
                }//while循环记住每一次必须有影响循环结的变化，不然容易死循环
                if(j==k){
                    break;
                }
                if(nums[j]+nums[k]==-tar){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                }

            }
                
            
            
        }
        return ans;
    }
};
// @lc code=end

