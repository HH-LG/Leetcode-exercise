#include <vector>
#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    Node* tail;
    int val;
    Node(){next = nullptr; tail = nullptr; val = 0;};
    Node(int val):val(val){next = nullptr; tail = nullptr;};

    void insertTail(Node* n)
    {
        if (tail)
        {
            tail->next = n;
            tail = n;
        }
        else
        {
            next = n;
            tail = n;
        }
    }

    vector<int> getArray()
    {
        Node* cur = this;
        vector<int> res;
        while(cur->next)
        {
            cur = cur->next;
            res.push_back(cur->val);
        }
        return res;
    }

    ~Node()
    {
        delete next;
    }
};


void radixSort(vector<int>& nums)
{
    bool positive = true;
    int radix = 10;
    while(positive)
    {
        positive = false;
        Node* bucket[10];
        for (int i = 0; i < 10; i++)
        {
            bucket[i] = new Node();
        }
        // distribute
        for (auto num: nums)
        {
            int digit = num % radix / (radix / 10);
            Node *n = new Node(num);
            bucket[digit]->insertTail(n);
            if (digit)
                positive = true;
        }
        // collect
        nums.clear();
        radix *= 10;
        for (int i = 0; i < 10; i++)
        {
            vector<int> subArray = bucket[i]->getArray();
            for (auto num: subArray)
            {
                nums.push_back(num);
            }
            delete bucket[i];
        }
    }
}

int main()
{
    vector<int> a {998, 88, 124, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    radixSort(a);
    for (auto num: a)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}