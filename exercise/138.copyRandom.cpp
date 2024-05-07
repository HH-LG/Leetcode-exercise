#include "List.h"
#include <unordered_map>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        Node* cur = new Node(head->val);
        Node* res = cur, *ori = head;
        while(head->next)
        {
            head = head->next;
            Node* tmp = new Node(head->val);
            cur->next = tmp;
            cur = cur->next;
        }
        unordered_map<Node*, Node*> map;
        cur = res;
        head = ori;
        while(head)
        {
            map[head] = cur;
            head = head->next;
            cur = cur->next; 
        }
        map[nullptr] = nullptr;

        cur = res;
        head = ori;
        while(cur)
        {
            cur->random = map[head->random];
            head = head->next;
            cur = cur->next; 
        }
        return res;
    }
};