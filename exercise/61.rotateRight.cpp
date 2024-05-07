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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        ListNode *fast, *slow, *tail;
        fast = slow = tail = head;
        int len = 1;
        while(tail->next)
        {
            tail = tail->next;
            len++;
        }
        int r = k % len;
        if (r == 0)
            return head;
        for (int i = 0; i < r; i++)
        {
            fast = fast->next;
        }
        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        tail->next = head;
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        return tmp;
    }
};