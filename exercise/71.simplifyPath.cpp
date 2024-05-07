#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    void findNotSlash(int &idx, string path)
    {
        int len = path.length();
        while (idx < len)
        {
            if (path[idx] != '/')
                break;
            idx++;
        }
    }
    void findSlash(int &idx, string path)
    {
        int len = path.length();
        while (idx < len)
        {
            if (path[idx] == '/')
                break;
            idx++;
        }
    }
public:
    string simplifyPath(string path) {
        int idx = 0, len = path.length();
        stack<string> cStack;
        string up = "..", now = ".";

        while (idx < len)
        {
            findNotSlash(idx, path);
            int begin = idx;
            cStack.push("/");
            findSlash(idx, path);
            int end = idx;
            if (end > begin)
            {
                string s = path.substr(begin, end - begin);
                if (s == up)
                {
                    cStack.pop();
                    while(!cStack.empty())
                    {
                        if (cStack.top() == "/")
                        {
                            cStack.pop();
                            break;
                        }
                        cStack.pop();
                    }
                }
                else if (s == now)
                {
                    cStack.pop();
                }
                else 
                {
                    cStack.push(s);
                }
            }
            else
                cStack.pop();
        }
        if (cStack.empty())
            cStack.push("/");
        string res;
        while (!cStack.empty())
        {
            res = cStack.top() + res;
            cStack.pop();
        }
        return res;
        
    }
};

