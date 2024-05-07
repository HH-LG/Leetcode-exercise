#include"List.h"
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head->next == nullptr)
            return head;
        ListNode *fast, *slow;
        ListNode dummy(0, head);
        int val = head->val;
        bool delFast = false;
        fast = slow = &dummy;
        fast = fast->next;
        while (fast->next != nullptr)
        {
            if (val == fast->next->val)
            {
                fast= fast->next;
                delFast = true;
            }
            else if (delFast)
            {
                fast = fast->next;
                slow->next = fast;
                val = fast->val;
                delFast = false;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
                val = fast->val;
            }
        }
        if (delFast)
        {
            fast = fast->next;
            slow->next = fast;
        }
        return dummy.next;
    }
};