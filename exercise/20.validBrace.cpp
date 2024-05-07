#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool match(char a, char b)
    {
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
    }

    bool isLeft(char a)
    {
        return a == '(' || a == '[' || a == '{';
    }

    bool isValid(string s) {
        stack<char> cStack;
        int len = s.length();
        cStack.push('#');
        for (int i = 0; i < len; i++)
        {
            char ch = cStack.top();
            if (isLeft(s[i]))
            {
                cStack.push(s[i]);
            }
            else if (match(ch, s[i]))
            {
                cStack.pop();
            }
            else
            {
                return false;
            }
        }
        return cStack.top() == '#';
    }
};