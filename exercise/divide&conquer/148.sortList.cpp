#include"List.h"
#include<bits/stdc++.h>
using namespace std;
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
    ListNode* sortList(ListNode* head, int len)
    {
        if (len == 1)
        {
            return head;
        }
        int mid = len / 2, cnt = 0;
        ListNode* cur = head, *prev;

        while(cur && cnt != mid)
        {
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        prev->next = nullptr;
        ListNode* l = sortList(head, mid);
        ListNode* r = sortList(cur, len - mid);
        ListNode dummy;
        cur = &dummy;
        while(l && r)
        {
            if (l->val < r->val)
            {
                cur->next = l;
                l = l->next;
                cur = cur->next;
            }
            else
            {
                cur->next = r;
                r = r->next;
                cur = cur->next;
            }
        }
        l = l ? l : r;
        while(l)
        {
            cur->next = l;
            l = l->next;
            cur = cur->next;
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head)
            return nullptr;
        int len = 0;
        ListNode *cur = head;
        while(cur)
        {
            cur = cur->next;
            len++;
        }
        return sortList(head, len);
    }
};

// bottom to up merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head)
            return nullptr;
        int len = 0;
        ListNode *cur = head;
        while(cur)
        {
            cur = cur->next;
            len++;
        }
        ListNode dummy(0, head);
        for (int subLen = 1; subLen < len; subLen <<= 1)
        {
            ListNode *prev = &dummy, *cur = dummy.next;
            while(cur)
            {
                ListNode* l = cur, *r = nullptr, *tail = nullptr;
                int cnt = 0;
                while(cur && cnt != subLen)
                {
                    tail = cur;
                    cur = cur->next;
                    cnt++;
                }
                if (tail)
                    tail->next = nullptr;
                r = cur;
                cnt = 0;
                while(cur && cnt != subLen)
                {
                    tail = cur;
                    cur = cur->next;
                    cnt++;
                }
                if (tail)
                    tail->next = nullptr;
                while(l && r)
                {
                    if (l->val < r->val)
                    {
                        prev->next = l;
                        l = l->next;
                        prev = prev->next;
                    }
                    else
                    {
                        prev->next = r;
                        r = r->next;
                        prev = prev->next;
                    }
                }
                l = l ? l : r;
                while(l)
                {
                    cout << "here" << endl;
                    prev->next = l;
                    l = l->next;
                    prev = prev->next;
                }
            }
        }
        return dummy.next;
    }
};