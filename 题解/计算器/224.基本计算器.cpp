// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <string>
#include <cctype>
#include "commoncppproblem224.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */
/*
 基本思路，利用两个栈来进行计算，一个栈用来存放数，一个栈用来存放符号
 1：现对源输入的字符串进行规范化处理，保证输入安全，具体如下：
    1:去除空格；
    2：在
 2：在简化了情况之后，在进行操作，具体如下：
    '('压入符号栈；
    ')'对栈内'('之后的数字进行集中运算，并将运算过的符号和数字出栈，将结果入栈；
    '+'，'-'，将符号入栈；
 */
      /* 测试用例：
           "+48 + -48"  
           "+48 + +48" 
           "+48 - -48" 
            "+48 - +48"
           增加下面的代码
      
        s = s.replaceAll("\\-\\-", "+"); 
        s = s.replaceAll("\\+\\-", "-"); 
        s = s.replaceAll("\\-\\+", "-"); 
        s = s.replaceAll("\\+\\+", "+"); 
        */
// @lc code=start
class Solution {
public:
    
    //处理字符串
    void replace_s(string& s){
            int pos = s.find(" ");
            while (pos != -1) {
                s.replace(pos, 1, "");
                pos = s.find(" ");
            }

    }

    int calculate1(string s) {
        stack<int> nums;
        stack<char> ops;
        // 为了防止第一个数为负数，先往 nums 加个 0
        nums.push(0);
        replace_s(s);
        //两个栈来进行计算
        int n = s.size();
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c == '('){
                ops.push(c);
            }else if(c == ')') {
                // 计算到最近一个左括号为止
                while(!ops.empty()) {
                    char op = ops.top();
                    if(op != '(')
                        calc(nums, ops);
                    else {
                        ops.pop();
                        break;
                    }
                }
            }else {
                if(isdigit(c)) {//判断数字
                    int cur_num = 0;
                    int j = i;
                    // 将从 i 位置开始后面的连续数字整体取出，加入 nums
                    while(j <n && isdigit(s[j])){
                        // 加括号确保了：先进行字符到数字的转换（s[j++] - '0'）然后才进行乘法结果的相加这样避免了在中间步骤中将字符的 ASCII 值与可能很大的数字相加，减少了溢出的可能性。
                        cur_num = cur_num*10 + (s[j++] - '0');
                   
                    }
                    nums.push(cur_num);
                    i = j-1;
                }
                else {
                    if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                        nums.push(0);
                    }
                    // 有一个新操作要入栈时，先把栈内可以算的都算了
                    while(!ops.empty() && ops.top() != '(')
                        calc(nums, ops);
                    ops.push(c);
                }
            }
        }
        
        
        while(!ops.empty()){
            calc(nums, ops);
        }
            
        return nums.top();
        
    }
    void calc(stack<int> &nums, stack<char> &ops) {
        if(nums.size() < 2 || ops.empty())
            return;
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(op == '+' ? a+b : a-b);
    }
    /*官解。更可能写出来的解法，
    思路：若（前面的符号为-，择所有符号变化

    */
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;

        for(i;i<n;i++){
            if(s[i]==' '){
                
            }else if(s[i]=='('){
                ops.push(sign);

            }else if(s[i]==')'){
                ops.pop();
            }else if(s[i]=='+'){
                sign=ops.top();
            }else if(s[i]=='-'){
                sign=-ops.top();
            }else {
                long num=0;
                
                while(i<n&&isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i--;
                ret=ret+sign*num;
                
            }
        }
        // while (i < n) {
        //     if (s[i] == ' ') {
        //         i++;
        //     } else if (s[i] == '+') {
        //         sign = ops.top();
        //         i++;
        //     } else if (s[i] == '-') {
        //         sign = -ops.top();
        //         i++;
        //     } else if (s[i] == '(') {
        //         ops.push(sign);
        //         i++;
        //     } else if (s[i] == ')') {
        //         ops.pop();
        //         i++;
        //     } else {
        //         long num = 0;
        //         while (i < n && s[i] >= '0' && s[i] <= '9') {
        //             num = num * 10 + s[i] - '0';
        //             i++;
        //         }
        //         ret += sign * num;
        //     }
        // }
        return ret;
    }


};
// @lc code=end

