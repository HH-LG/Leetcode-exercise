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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode *before, *after;
        ListNode *start, *end;
        ListNode *cur = head;

        for (int i = 0; i < right - 1; i++)
        {
            if (i == left - 2)
                before = cur;
            if (i == left - 1)
                start = cur;
            cur = cur->next;
        }
        if (left == 1)
        {
            before = nullptr;
            start = head;
        }
        if (left == 2)
            before = head;
        end = cur;
        after = cur->next;

        end->next = start;
        cur = start;
        ListNode *prev = end;
        while(cur != end)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        cur->next = prev;
        
        if (before)
            before->next = end;
        start->next = after;
        return left == 1 ? end : head;
    }
};
