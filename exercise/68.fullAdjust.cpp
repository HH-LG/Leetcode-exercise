#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string whiteStr(int n)
    {
        return string(n, ' ');
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int width = 0;
        vector<string> lineWords;
        for (int i = 0; i < (int)words.size(); i++)
        {
            int leni = words[i].length();
            int newWidth = width + (bool)width + leni;
            if (newWidth <= maxWidth)
            {
                width = newWidth;
            }
            else
            {
                string line = "";
                int wordsLen = 0;
                for (auto word: lineWords)
                    wordsLen += word.length();
                int wordsCnt = (int)lineWords.size();
                int white = maxWidth - wordsLen;
                int whiteAvg, whiteRest;
                vector<string> lineWhite;
                if (wordsCnt != 1)
                {
                    whiteAvg =  white / (wordsCnt - 1);
                    whiteRest = white % (wordsCnt - 1);
                }
                else
                {
                    lineWhite.push_back(whiteStr(white));
                }
                for (int j = 0; j < wordsCnt - 1; j++)
                {
                    lineWhite.push_back(whiteStr(whiteAvg + (whiteRest > 0)));
                    whiteRest--;
                }
                for (int j = 0; j < wordsCnt + (int)lineWhite.size(); j++)
                {
                    int idx = j / 2;
                    if (j % 2 == 0)
                    {
                        line += lineWords[idx];
                    }
                    else
                    {
                        line += lineWhite[idx];
                    }
                }
                res.push_back(line);
                lineWords.clear();

                width = words[i].length();
            }
            lineWords.push_back(words[i]);
        }
        if (lineWords.size() != 0)
        {
            string line = "";
            int wordsCnt = (int)lineWords.size();
            line += lineWords[0];
            for (int i = 1; i < wordsCnt; i++)
            {
                line += ' ' + lineWords[i];
            }
            int whiteLen = maxWidth - line.length();
            line += whiteStr(whiteLen);
            res.push_back(line);
        }
        return res;
    }
};