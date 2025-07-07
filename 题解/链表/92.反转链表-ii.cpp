// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem92.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr||head->next==nullptr||right-left<1){
            return head;
        }
        ListNode *dummy =new ListNode(0);
        dummy->next =head;
        ListNode *temp = dummy;
        int i;
        for(i=0;i<left-1;i++){
            temp=temp->next;
        }
        //头插法的关键是找到正确的三个指针，即虚拟头，尾部，现在往前插的节点
        ListNode* last = temp->next;
        ListNode* cur;
        for (i=0;i<right-left;i++){
             cur=last->next;
             last->next=cur->next;
             cur->next=temp->next;
             temp->next=cur;
             
        }
        


        return dummy->next;

    }
};
// @lc code=end

