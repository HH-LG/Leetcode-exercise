#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sMap[128] = {}, tMap[128] = {};
        for (auto c: s)
            sMap[c]++;
        for (auto c: t)
            tMap[c]++;
        for (int i = 'a'; i < 'z' + 1; i++)
            if (sMap[i] != tMap[i])
                return false;
        return true;
    }
};