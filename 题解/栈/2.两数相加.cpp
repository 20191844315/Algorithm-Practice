// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem2.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* a=l1;
        ListNode* b=l2;
        ListNode* c=head;
        int temp=0;
        while(a!=nullptr&&b!=nullptr){
            int res=a->val+b->val+temp;
            temp =0;
            if(res>9){
                temp=1;
            }
            ListNode* tempptr=new ListNode(res%10);
            
            c->next=tempptr;
            c=c->next;
            a=a->next;
            b=b->next;
        }
        //处理尾部
        
        while(a!=nullptr){
            int res=a->val+temp;
            temp=0;
            if(res>9){
                temp=1;
            }
            ListNode* tempptr=new ListNode(res%10);
            
            c->next=tempptr;
            c=c->next;
            a=a->next;
        }
        while(b!=nullptr){
            int res=b->val+temp;
            temp=0;
            if(res>9){
                temp=1;
            }
            ListNode* tempptr=new ListNode(res%10);
            
            c->next=tempptr;
            c=c->next;
            b=b->next;
        }
        //最后进位
        if(temp==1){
            ListNode* tempptr=new ListNode(1);
            
            c->next=tempptr;
        }
        return head->next;

        
        
    }
};
// @lc code=end

