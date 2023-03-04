class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
    
        for (auto i = 0; i < nums.size(); i++) {
            auto search = target - nums.at(i);
            cout << nums.size() << "\n";
            auto f = find(nums.begin(), nums.end(), search);
            if (f != nums.end()) {
                if (f - nums.begin() == i) {
                    res.clear();
                    continue;
                }
                res.push_back(i);
                res.push_back(f - nums.begin());
                break;
            }
            res.clear();
        }
        return res;
    }
};