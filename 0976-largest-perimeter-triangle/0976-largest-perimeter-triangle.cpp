class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // triangle inequality theorem
        // a+b > c, a+c > b, and b+c > a
        
        sort(nums.begin(), nums.end());
        
        for (auto i = nums.size() - 1; i >= 2; i--) {
            if (nums[i - 2] + nums[i - 1] <= nums[i]) {
                continue;
            } else {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
            
        }
        
        return 0;
    }
};