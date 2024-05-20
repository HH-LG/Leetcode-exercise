#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> allStr;
        vector<int> idx;

        for (auto str: words)
        {
            allStr[str]++;
        }

        int lenWord = words[0].length();
        int len = s.length();

        for (int group = 0; group < lenWord; group++)
        {
            int start = group;
            int end = group;
            int size = 0;
            map<string, int> strSet;
            while (start + lenWord * words.size() <= len)
            {
                int startIdx = end;
                bool notFind = true;
                while(notFind && startIdx < len)
                {
                    for (auto pair: allStr)
                    {
                        string w = pair.first;
                        string subString = s.substr(startIdx, lenWord);
                        if (w == subString)
                        {
                            notFind = false;
                            break;
                        }
                    }
                    if (notFind)
                        startIdx += lenWord;
                }

                if (!notFind)
                {
                    string subString = s.substr(startIdx, lenWord);
                    if (startIdx != end)
                    {
                        start = startIdx;
                        strSet.clear();
                        size = 0;
                    }
                    end = startIdx + lenWord;

                    while (strSet[subString] == allStr[subString])
                    {
                        string tempString = s.substr(start, lenWord);
                        strSet[tempString]--;
                        size --;
                        start += lenWord;
                    }
                    strSet[subString]++;
                    size ++;
                }
                else
                    break;
            
                if (size == (int)words.size())
                    idx.push_back(start);
            }
        }
        return idx;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.length(), wordLen = words[0].length(), wSize = words.size();
        vector<int> res;
        for (int group = 0; group < wordLen && group + wordLen * wSize <= len; group++)
        {
            unordered_map<string, int> count;
            for (int i = 0; i < wSize; i++)
            {
                count[s.substr(group + i * wordLen, wordLen)]++;
                count[words[i]]--;
            }
            for (string w: words)
            {
                if (count[w] == 0)
                    count.erase(w);
            }
            if (count.empty())
            {
                res.push_back(group);
            }
            for (int start = group + wordLen; start + wordLen * wSize <= len; start += wordLen)
            {
                string r = s.substr(start - wordLen, wordLen);
                string a = s.substr(start + wordLen * (wSize - 1), wordLen);
                count[r]--;
                count[a]++;
                if (count[r] == 0)
                    count.erase(r);
                if (count[a] == 0)
                    count.erase(a);
                if (count.empty())
                    res.push_back(start);
            } 
        }
        return res;
    }
};