class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (auto i = 0; i < nums.size(); i++) {
            auto query = target - nums.at(i);
            cout << query << "\n";
            auto out = find(nums.begin(), nums.end(), query);
            if (out != nums.end()) {
                auto index = out - nums.begin();
                if (i == index) {
                    continue;
                }
                res.push_back(i);
                res.push_back(index);
                break;
            }
        }
        return res;
    }
};