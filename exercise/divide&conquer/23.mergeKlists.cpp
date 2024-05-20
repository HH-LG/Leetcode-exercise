#include"List.h"
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool allNull(vector<ListNode*> &cur)
    {
        for (auto node : cur)
        {
            if (node)
                return false;
        }
        return true;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num = lists.size();
        vector<ListNode*> cur(num);
        ListNode dummy, *prev;
        for (int i = 0; i < num; i++)
        {
            cur[i] = lists[i];
        }
        prev = &dummy;
        while(!allNull(cur))
        {
            int idx = -1;
            int minVal = INT_MAX;
            for (int i = 0; i < num; i++)
            {
                if (!cur[i])
                    continue;
                if (cur[i]->val < minVal || idx == -1)
                {
                    idx = i;
                    minVal = cur[i]->val;
                }
            }
            prev->next = cur[idx];
            cur[idx] = cur[idx]->next;
            prev = prev->next;
            prev->next = nullptr;
        }
        return dummy.next;
    }
};