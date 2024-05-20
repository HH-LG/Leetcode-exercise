#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int magMap[128] = {}, ranMap[128] = {};
        for (auto ch:magazine)
            magMap[ch] ++;
        for (auto ch:ransomNote)
            ranMap[ch] ++;
        
        for (int i = 0; i < 26; i++)
        {
            int ch = i + 'a';
            if (magMap[ch] < ranMap[ch]) 
            {
                return false;
            }
        }
        return true;
    }
};