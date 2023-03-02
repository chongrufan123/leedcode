/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* h = new ListNode;
        h->next = nullptr;
        ListNode* p = head;
        ListNode* q;
        while(p != nullptr){
            if(q != nullptr) q = p->next;
            p->next = h->next;
            h->next = p;
            p = q;
        }
        h = h->next;
        return h;
    }
};
// @lc code=end

