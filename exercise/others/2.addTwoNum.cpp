#include "List.h"
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
        ListNode* res = new ListNode();
        ListNode* cur = res;
        int cf = 0;
        while(l1 && l2)
        {
            cur->val = (l1->val + l2->val + cf) % 10;
            cf = (l1->val + l2->val + cf) / 10;
            if (l1->next || l2->next)
            {
                ListNode* tmp = new ListNode();
                cur->next = tmp;
                cur = cur->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        l1 = l1 ? l1 : l2;
        while(l1)
        {
            cur->val = (l1->val + cf) % 10;
            cf = (l1->val + cf) / 10;
            if (l1->next)
            {
                ListNode* tmp = new ListNode();
                cur->next = tmp;
                cur = cur->next;
            }
            l1 = l1->next;
        }
        if (cf)
        {
            ListNode* tmp = new ListNode(1);
            cur->next = tmp;
            cur = cur->next;
        }
        return res;
    }
};