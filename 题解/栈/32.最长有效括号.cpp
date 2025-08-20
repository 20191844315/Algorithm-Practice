/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    /*栈的思路
    栈中存放的是上一个不能匹配的（的位置。
    一次遍历，先在栈中存一个-1，表面起点的前一个位置。
        遇到（：存入序号；
        遇到）：出栈，
            若栈空，）不能匹配，则将）所在的位置变成新的起点前一个的位置
            若不空，则计算此时的距离。i-st.top()
    */
    int longestValidParentheses1(string s) {
        stack<int> st;
        st.push(-1); // 初始化栈，用于处理边界条件
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // 遇到 '(', 压入索引
            } else {
                st.pop();    // 遇到 ')', 弹出栈顶
                if (st.empty()) {
                    st.push(i); // 栈为空，说明当前 ')' 无法匹配，压入索引
                } else {
                    max_len = std::max(max_len, i - st.top()); // 更新最大值
                }
            }
        }
        return max_len;
    }
    //动态规划
    int longestValidParentheses(string s) {
        int n=s.size();
        int maxans=0;
        vector<int>dp(n,0);
        if(n==0||n==1){
            return 0;
        }
        
        for(int i=1;i<n;i++){
            
            if(s[i]==')'){
                if(s[i-1]=='('){
                    
                    dp[i]=(i>=2?dp[i-2]:0)+2;
                }else if(i-dp[i-1]>=1&&s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+2+(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0);
                }
                maxans=max(maxans,dp[i]);
            }
        }

        
        return maxans;
    }
};
// @lc code=end

