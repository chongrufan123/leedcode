/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p =list1;
        ListNode* q =list2;
        ListNode* ans = new ListNode;
        ListNode* a = ans;
        while(p != nullptr && q != nullptr){
            if(p->val >= q->val){
                a->next = q;
                a = q;
                if(q != nullptr) q = q->next;
            }
            else{
                a->next = p;
                a = p;
                if(p != nullptr) p = p->next;
            }
        }
        if(p != nullptr) a->next = p;
        if(q != nullptr) a->next = q;
        return ans->next;
    }
};
// @lc code=end

