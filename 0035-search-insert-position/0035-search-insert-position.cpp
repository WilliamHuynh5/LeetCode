class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto res = recur(nums, target, 0, nums.size() - 1);
        return res;
    }
    
    int recur(vector<int>& nums, int target, int low, int high) {
        auto mid = (low + high) / 2;
        if (low > high) {
            if (isValidRight(nums, high, target)) {
                return mid + 1;
            } else if (isValidLeft(nums, low, target)) {
                return mid;
            }
        } else {
            if (target == nums.at(mid)) {
                return mid;
            }else if (target > nums.at(mid)) {
                return recur(nums, target, mid + 1, high);
            } else {
                return recur(nums, target, low, mid - 1);
            }
        }
        return mid;
    }
    
    int isValidRight(vector<int>& nums, int high, int target) {
        try {
            if (target > nums.at(high)) {
                return true;
            }
            return false;
        } catch(...) {
            return false;
        }
    }
    
    int isValidLeft(vector<int>& nums, int low, int target) {
        try {
            if (target < nums.at(low)) {
                return true;
            }
            return false;
        } catch(...) {
            return false;
        }
    }
};