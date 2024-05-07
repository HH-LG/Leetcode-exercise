#include <vector>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (map.count(val))
        {
            return false;
        }
        int len = (int)nums.size();
        nums.push_back(val);
        map.insert(make_pair(val, len));
        return true;
    }
    
    bool remove(int val) {
        if (!map.count(val))
        {
            return false;
        }
        int index = map[val], len = (int)nums.size();
        map.erase(nums[len - 1]);
        map.insert(make_pair(nums[len - 1], index));
        swap(nums[index], nums[len - 1]);
        nums.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int len = (int)nums.size();
        int index = rand()%len;
        return nums[index];
    }
private:
    vector<int> nums;
    unordered_map<int, int> map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */