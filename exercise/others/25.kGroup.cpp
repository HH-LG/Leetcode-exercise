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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        int i = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *cur = head, *p = head;
        while(true)
        {
            p = cur;
            ListNode* last = cur;
            do
            {
                cur = cur->next;
                i++;
            }
            while(i % k != 0 && cur != nullptr);

            if (i % k != 0)
                break;
            for (int i = 0; i < k; i++)
            {
                ListNode* tmp = p->next;
                p->next = prev->next;
                prev->next = p;
                p = tmp;
            }
            prev = last;
        }
        prev->next = p;
        return dummy->next;
    }
};