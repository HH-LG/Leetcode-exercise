#include <stack>

using namespace std;

class MinStack {
    struct element
    {
        int value;
        int min;
    };
    stack<element> s;

public:
    MinStack() {
    }
    
    void push(int val) {
        element e;
        e.value = val;
        if (s.empty())
        {
            e.min = val;
        }
        else
        {
            e.min = min(s.top().min, val);
        }
        s.push(e);
    }
    
    void pop() {
        if (!s.empty())
        {
            s.pop();
        }
    }
    
    int top() {
        if (!s.empty())
        {
            return s.top().value;
        }
        return -1;
    }
    
    int getMin() {
        if (!s.empty())
        {
            return s.top().min;
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */