/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int,string>> stk;
        string res="";
        int multi=0;
        for(char c:s){
            if(isdigit(c)){//使用 isdigit() 判断数字字符
                multi=multi*10+(c-'0');
            }else if(c=='['){
                stk.push({multi,res});
                multi=0;
                res="";

            }else if(c==']'){
                auto [cur_m,last_res]=stk.top();//使用结构化绑定 auto [cur_multi, last_res] 来解构 pair
                stk.pop();
                string temp="";
                for(int i=0;i<cur_m;i++){
                    temp=temp+res;
                }
                res=last_res+temp;
            }
            else{
                res=res+c;
            }

        }

        return res;
    }
};
// @lc code=end

