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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        ListNode* less = new ListNode(0);
        ListNode* more = new ListNode(0);

        ListNode* cur = head, *p1 = less, *p2 = more;
        while(cur)
        {
            if (cur->val < x)
            {
                p1->next = cur;
                p1 = p1->next ;
                cur = cur->next;
                p1->next = nullptr;
            }
            else
            {
                p2->next = cur;
                p2 = p2->next ;
                cur = cur->next;
                p2->next = nullptr;
            }
        }
        p1->next = more->next;
        ListNode* res = less->next;
        delete less, more;
        return res;
    }
};