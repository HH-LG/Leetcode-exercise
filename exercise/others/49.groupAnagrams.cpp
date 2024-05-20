#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <hash_fun.h>

using namespace std;

class Solution {
public:
    struct word {
        int idx;
        int map[128] = {};
    };
    
    static bool w_comp(word w1, word w2)
    {
        for (int i = 'a'; i < 'z' + 1; i++)
            if (w1.map[i] < w2.map[i])
                return false;
        return true;
    }

    bool w_equal(word w1, word w2)
    {
        for (int i = 'a'; i < 'z' + 1; i++)
            if (w1.map[i] != w2.map[i])
                return false;
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0)
            return {{}};
        vector<vector<string>> res;
        vector<word> ids;
        for (int i = 0; i < strs.size(); i++)
        {
            word s;
            s.idx = i;
            for (auto ch: strs[i])
                s.map[ch] ++;
            ids.push_back(s);
        }
        sort(ids.begin(), ids.end(), w_comp);
        vector<string> group;
        group.push_back(strs[ids[0].idx]);
        for (int i = 0; i < strs.size() - 1; i++)
        {
            if (w_equal(ids[i], ids[i + 1]))
            {
                group.push_back(strs[ids[i + 1].idx]);
            }
            else
            {
                res.push_back(group);
                group.clear();
                group.push_back(strs[ids[i + 1].idx]);
            }
        }
        res.push_back(group);
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t
            {
                int res = 0;
                for (auto ele: arr)
                {
                    res <<= 1;
                    res ^= ele;
                }
                return res;
            };
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> map(0, arrayHash);
        for (string s: strs)
        {
            array<int, 26> count{};
            for (auto ch: s)
            {
                count[ch - 'a']++;
            }
            map[count].push_back(s);
        }
        vector<vector<string>> res;
        for (auto group: map)
        {
            res.push_back(group.second);
        }
        return res;
    }
};