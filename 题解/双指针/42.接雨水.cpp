/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    //双指针,i是前一个峰的位置，j是后一个峰的位置，找到凹陷，计算。
    int trap1(vector<int>& height) {
        int n=height.size();
        int tap=0;
        int sum=0;
        int i=0;
        // //去掉前面的0,实际不需要
        // for(i;i<n;i++){
        //     if(height[i]){
        //         break;
        //     }
        // }
        
        int j=i+1;
        while(j<n){
            j=i+1;
           
            for(j;j<n;j++){
                if(height[j]>=height[i]){
                    break;
                }
            }

            if(j==n){
                tap=1;
                break;
                //此时一路下坡，i是最后一个最高的桶。
            }
            //水接在i+1和j-1之间

            for(int k=i+1;k<j;k++){
                sum+=min(height[j],height[i])-height[k];
            }
            i=j;
        }

        if(tap){
            int max=i;
            i=n-1;
            j=n-2;
            while(j>=max){
                j=i-1;
                for(j;j>=max;j--){
                    if(height[j]>=height[i]){
                        break;
                    }
                }
                for(int k=i-1;k>j;k--){
                    sum+=min(height[j],height[i])-height[k];
                }
                i=j;
            }
        }

        return sum;
        
    }


    //官解思路，双指针，按列处理接水量
    int trap2(vector<int>& height) {
        int ans=0;
        int left=0,right=height.size()-1;
        int lmax=0,rmax=0;
        while(left<right){
            lmax=max(height[left],lmax);
            rmax=max(height[right],rmax);
            if(height[left]<height[right]){
                ans+=min(lmax,rmax)-height[left];
                left++;
            }else {
                 ans+=min(lmax,rmax)-height[right];
                 right--;
            }
            
        }
        return ans;
    }
    /*官解思路，dp,
      对于下标 i，下雨后水能到达的最大高度等于下标 i 两边的最大高度的最小值,三次遍历
    */
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }

};
// @lc code=end

