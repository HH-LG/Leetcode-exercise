#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool braced(string s)
    {
        int len = s.length();
        if (s[0] != '(' || s[len - 1] != ')')
        {
            return false;
        }
        int cnt = 0;
        for (int i = 1; i < len - 1; i++)
        {
            if (s[i] == '(')
                cnt++;
            if (s[i] == ')')
                cnt--;
            if (cnt < 0)
                return false;
        }
        return true;
    }
    int eval(string s)
    {
        int len = s.length();
        int brace = 0;
        int idx = -1;
        int val;
        if (len == 0)
            return 0;
        if (braced(s))
            return eval(s.substr(1, len - 2));
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                brace++;
            }
            else if (s[i] == ')')
            {
                brace--;
            }
            else if ((s[i] == '+' || s[i] == '-') && !brace)
            {
                idx = i;
            }
        }
        if (idx == -1)
        {
            return atoi(s.c_str());
        }
        if (s[idx] == '+')
        {
            return eval(s.substr(0, idx)) + eval(s.substr(idx + 1, len - idx - 1));
        }
        else 
        {
            return eval(s.substr(0, idx)) - eval(s.substr(idx + 1, len - idx - 1));
        }
    }
    int calculate(string s) {
        string filtered;
        for (auto ch: s)
            if (ch != ' ')
                filtered += ch;
        return eval(filtered);
    }
};

if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                        nums.push(0);
                    }

作者：宫水三叶
链接：https://leetcode.cn/problems/basic-calculator/solutions/1/shuang-zhan-jie-jue-tong-yong-biao-da-sh-olym/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        int sign = 1, ret = 0;
        ops.push(1);

        int idx = 0, len = s.length();
        while(idx < len)
        {
            if (s[idx] == '+')
            {
                sign = ops.top();
                idx++;
            }
            else if (s[idx] == '-')
            {
                sign = -ops.top();
                idx++;
            }
            else if (s[idx] == '(')
            {
                ops.push(sign);
                idx++;
            }
            else if (s[idx] == ')')
            {
                ops.pop();
                idx++;
            }
            else if (s[idx] == ' ')
            {
                idx++;
            }
            else
            {
                int num = 0;
                while(s[idx] >= '0' && s[idx] <= '9')
                {
                    num *= 10;
                    num += s[idx] - '0';
                    idx++;
                }
                ret += num * sign;
            }
        }
        return ret;
    }
};
