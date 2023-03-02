/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        while(p != nullptr){
            while(q != nullptr){
                if(p == q) return p;
                if(p != nullptr) p = p->next;
                if(q != nullptr) q = q->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end

