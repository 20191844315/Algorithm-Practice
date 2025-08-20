/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    stack<int> a, b;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);

    }
    
    int pop() {
        int peek=this->peek();
        b.pop();
        return peek;
    }
    
    int peek() {
        if(!b.empty()){
            return b.top();
        }
        if(a.empty()){
            return -1;
        }
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        
        int x=b.top();
        
        return x;
    }
    
    bool empty() {
        return a.empty()&&b.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

