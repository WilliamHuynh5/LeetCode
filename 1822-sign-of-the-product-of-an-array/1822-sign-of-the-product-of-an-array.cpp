class Solution {
public:
    int arraySign(vector<int>& nums) {
        if (find(nums.begin(), nums.end(), 0) != nums.end()){
            return 0;
        }
        
        auto sign = 1;
        for (auto num : nums) {
            (num < 0) ? sign *= -1 : sign *= 1;
        }
        return sign;
    }
};