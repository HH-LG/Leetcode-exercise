#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
    bool isOp(string s)
    {
        return s.length() == 1 && (s == "+" || s == "-" || s == "*" || s == "/");
    }
    int calcu(int a, string op, int b)
    {
        if (op == "+")
        {
            return a + b;
        }
        else if (op == "-")
        {
            return a - b;
        }
        else if (op == "/")
        {
            return a / b;
        }
        else if (op == "*")
        {
            return a * b;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int len = tokens.size();
        for (int i = 0; i < len; i++)
        {
            if (isOp(tokens[i]))
            {
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();
                int res = calcu(operand1, tokens[i], operand2);
                s.push(res);
            }
            else
            {
                int n = atoi(tokens[i].c_str());
                s.push(n);
            }
        }
        return s.top();
    }
};