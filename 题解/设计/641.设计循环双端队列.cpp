/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
private:
    int front,last;
    int n;
    int size;
    vector<int> a;
public:
    //关键
    MyCircularDeque(int k) {
        a.resize(k);
        size=0;
        n=k;
        front =0;
        last=k-1;
    }
    
    bool insertFront(int value) {
        if(this->isFull()){
            return false;
        }
        front=(front-1+n)%n;
        a[front]=value;
        size++;
        return true;
        
    }
    
    bool insertLast(int value) {
        if(this->isFull()){
            return false;
        }
        last=(last+1)%n;
        a[last]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(this->isEmpty()){
            return false;
        }
        front=(front+1)%n;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(this->isEmpty()){
            return false;
        }
        last=(last-1+n)%n;
        size--;
        return true;
    }
    
    int getFront() {
        if(this->isEmpty()){
            return -1;
        }
        return a[front];
    }
    
    int getRear() {
        if(this->isEmpty()){
            return -1;
        }
        return a[last];
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }else{
            return false;
        }
    
    }
    
    bool isFull() {
        if(size==n){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

