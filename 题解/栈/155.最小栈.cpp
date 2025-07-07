/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    stack<long long> stk;
    stack<int> min_stk;//常规思路，构造一个栈存放最小值，同进同出。
    long long min;//两个int范围的整数可能减出超范围的数，注意overflow
    //stack<int> min_stack;
public:
    MinStack() {
        min=INT_MAX;
    }
    
    void push(int val) {
        if(stk.empty()){
            min =val;
            stk.push(0);
        }else{
            long long diff=(long long)val-min;// 显式转换防止溢出
            if(diff<0){
                min=val;
            }
            stk.push(diff);
        }
        
        
    }
    
    void pop() {
        if(stk.empty()){
            return ;
        }
        long long diff=stk.top();
        if(diff<0){
            min=min-diff;
        }
        stk.pop();
        
    }
    
    int top() {
        long long diff=stk.top();
        if(diff<0){//当 val 是 INT_MAX，min 是 INT_MIN 时，diff = val - min 会超出 int 范围，导致未定义行为
            return (int)min;
        }else{
            long long val = diff+min;
            return (int)val;
        }
        
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

