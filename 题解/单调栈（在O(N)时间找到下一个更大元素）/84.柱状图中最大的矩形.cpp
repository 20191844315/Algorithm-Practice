/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    //暴力解 O(n2) 超时
    int largestRectangleArea1(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            int top=heights[i];
            int s=0;
            for(int j=0;j<n;j++){
                if(heights[j]>=top){
                    s+=top;
                }else{
                    ans=max(ans,s);
                    s=0;
                }
            }
             ans=max(ans,s);
        }
        return ans;
    }
    //以i为顶的矩形，底边长是左边第一个比他小的值和右边第一比他小的值，因此可以用单调栈来求解
    int largestRectangleArea2(vector<int>& heights) {
        int n=heights.size();
        
        int ans=0;
        stack<int> stk;
        vector<int> lmin(n,0);
        vector<int> rmin(n,0);
        //整理lmin,找左边第一个比他小的元素，在栈里存储一个递增栈，存放的是"等待找到更小元素"的索引
        for(int i=n-1;i>=0;i--){
            
            while(!stk.empty()&&heights[i]<heights[stk.top()]){
                lmin[stk.top()]=i;
                stk.pop();
            }
            
            
            stk.push(i);
        }
        while(!stk.empty()){
                lmin[stk.top()]=-1;
                stk.pop();
        }

        for(int i=0;i<n;i++){
            
            while(!stk.empty()&&heights[i]<heights[stk.top()]){
                rmin[stk.top()]=i;
                stk.pop();
            }
            
            
            stk.push(i);
        }
        while(!stk.empty()){
                rmin[stk.top()]=n;
                stk.pop();
        }

        for(int i=0;i<n;i++){
            ans=max(ans,(rmin[i]-lmin[i]-1)*heights[i]);
        }

        return ans;
    }
    //整理lmin,找左边第一个比他小的元素，在栈里存储一个递增栈，存放的是"所有后面可能的解"的索引，在遍历时，用自己替换掉不如自己的元素，这样永远在栈里挑解
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }


};


// @lc code=end

