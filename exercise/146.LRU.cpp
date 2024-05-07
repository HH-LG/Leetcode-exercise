#include<list>
#include<unordered_map>

using namespace std;

struct Node
{
    Node* next, *prev;
    int key;
    int val;
    Node(){};
    Node(int key, int val):key(key), val(val){};
};

class LRUCache {
    int size;

    struct data
    {
        int key;
        int val;
    };
    
    list<data> cache;
    unordered_map<int, list<data>::iterator> map;

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        int res = -1;
        for (auto it = cache.begin(); it != cache.end(); it++)
        {
            data tmp = *it;
            if (tmp.key == key)
            {
                cache.erase(it);
                cache.push_back(tmp);
                res = tmp.val;
                break;
            }
        }
        return res;
    }
    
    void put(int key, int value) {
        data d;
        d.key = key;
        d.val = value;
        if (map.count(key) != -1)
        {
            auto it = map[key];
            cache.erase(it);
        }
        
        cache.push_back(d);
        if (cache.size() > size)
        {
            cache.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
    int size;

    Node *head, *tail;
    unordered_map<int, Node*> cache;
public:
    LRUCache(int capacity) 
    {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        if (cache.count(key))
        {
            Node* n = cache[key];
            moveToTail(n);
            return n->val;
        }
        else
            return -1;
   }
    
    void put(int key, int value) 
    {
        if (cache.count(key))
        {
            Node* n = cache[key];
            n->val = value;
            moveToTail(n);
        }
        else
        {
            Node* n = new Node(key, value);
            pushBack(n);
            if (cache.size() > size)
            {
                removeNode(head->next);
            }
        }
    }

    void moveToTail(Node* p)
    {
        removeNode(p);
        pushBack(p);
    }
    void removeNode(Node* p)
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        cache.erase(p->key);
    }

    void pushBack(Node* p)
    {
        p->next = tail;
        p->prev = tail->prev;
        tail->prev->next = p;
        tail->prev = p;
        cache[p->key] = p;
    }
};
