class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto k = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};