class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchRecur(nums, target, 0, nums.size() - 1);
    }
    
    int searchRecur(vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        } else {
            auto mid = (low + high) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                return searchRecur(nums, target, mid + 1, high);
            }
            else {
                return searchRecur(nums, target, low, mid - 1);
            }
        }
    }
};