class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        auto sign = 1;
        for (auto num : nums) {
            if (num == 0) return 0;
            (num < 0) ? sign *= -1 : sign *= 1;
        }
        return sign;
    }
};