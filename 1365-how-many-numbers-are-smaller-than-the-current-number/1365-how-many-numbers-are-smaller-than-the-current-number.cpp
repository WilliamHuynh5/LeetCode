class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        auto temp = nums;
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (auto elem : temp) {
            auto idx = find(nums.begin(), nums.end(), elem) - nums.begin();
            res.push_back(idx);
        }
        return res;
    }
};