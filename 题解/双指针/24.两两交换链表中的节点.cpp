// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);//初始化空指针
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        //ListNode* temp =head;设立空的头结点
        while(temp->next!=nullptr&&temp->next->next!=nullptr){//小心temp->next->next!=nullptr的访问越界
            ListNode* slow =temp->next;
            ListNode* fast =temp->next->next;
            slow->next=fast->next;
            temp->next=fast;
            fast->next=slow;
            temp =slow;
        }
        ListNode* ans = dummyHead->next;
        delete dummyHead;//释放空间
        return ans;
    }
};
// @lc code=end

