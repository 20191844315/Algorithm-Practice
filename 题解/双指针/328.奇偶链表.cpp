// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem328.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        // O(1)尽量不要申请新结点
        // ListNode *temp=new ListNode(0);
        // ListNode *A=new ListNode(0);
        // ListNode *B=new ListNode(0);
        ListNode *a=head;
       
        ListNode *b=head->next;
         ListNode *current =head->next->next;
        ListNode *B=b;
        //不要使用temp->next->next;很容易出错
        // while(temp->next!=nullptr&&temp->next->next!=nullptr){
        //     a->next=temp->next;
        //     a=a->next;
        //     b->next=temp->next->next;
        //     b=b->next;
        //     temp=temp->next->next;
        // }
        while(b!=nullptr&&b->next!=nullptr){
            a->next =b->next;
            a=a->next;
            b->next=a->next;
            b=b->next;
        }
        a->next=B;
        return head;
    }
};
// @lc code=end

