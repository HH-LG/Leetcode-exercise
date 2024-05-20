#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> courseOrder;
        vector<int> inDegree(numCourses);
        unordered_map<int, vector<int>> afterMap;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            inDegree[course]++;
            if (!afterMap.count(prerequisite))
                afterMap[prerequisite] = vector<int>();
            afterMap[prerequisite].push_back(course);
        }
        stack<int> s;
        for (int i = 0;  i < numCourses; i++)
        {
            int course = i;
            if (inDegree[course] == 0)
            {
                s.push(course);
            }
        }
        while(!s.empty())
        {
            int course = s.top();
            s.pop();
            courseOrder.push_back(course);
            if (afterMap.count(course))
                for (int after: afterMap[course])
                {
                    inDegree[after]--;
                    if (inDegree[after] == 0)
                    {
                        s.push(after);
                    }
                }
        }
        return courseOrder.size() == numCourses ? courseOrder : vector<int>();
    }
};