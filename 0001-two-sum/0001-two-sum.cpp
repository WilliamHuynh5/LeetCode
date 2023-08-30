class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Iterate through an array, and calculate the difference
        // If the diference already exists, return current number and
        // and the difference as a pair, otherwise keep iterating.
        // Return {0, 0} if nothing found.
        
        map<int, int> m;
        
        for (auto i = 0; i < nums.size(); i++) {
            auto elem = nums.at(i);
            auto search = target - elem;
            if (m.count(search)) {
                return {m[search], i};
            } else {
                m[elem] = i;
            }

        }
        return {0, 0};
    }
};
    
/*
    vector<int> res;

    for (auto i = 0; i < nums.size(); i++) {
        auto search = target - nums.at(i);
        auto f = find(nums.begin(), nums.end(), search);
        if (f != nums.end()) {
            if (f - nums.begin() == i) {
                continue;
            }
            res.push_back(i);
            res.push_back(f - nums.begin());
            break;
        }
        res.clear();
    }
    return res;
*/