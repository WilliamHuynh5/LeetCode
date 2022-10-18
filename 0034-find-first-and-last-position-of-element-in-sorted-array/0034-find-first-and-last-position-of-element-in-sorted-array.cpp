class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};
        auto index_lowest = recur_lowest(nums, 0, nums.size() - 1, target);
        auto index_highest = recur_highest(nums, 0, nums.size() - 1, target);
        return vector<int>{index_lowest, index_highest};
    }
    
    int recur_lowest(vector<int> &nums, int lo, int hi, int target) {
        auto mid = (hi + lo) / 2;
        if (lo > hi) {
            return -1;
        } else {
            if (nums.at(mid) == target) {
                if (mid != 0 && nums.at(mid - 1) == target) {
                    return recur_lowest(nums, lo, mid - 1, target);
                } else {
                    return mid;
                }
            } 
            else if (target > nums.at(mid)) {
                return recur_lowest(nums, mid + 1, hi, target);
            } else if (target < nums.at(mid)){
                return recur_lowest(nums, lo, mid - 1, target);
            } 
        }
        return -1;
    }
    
    int recur_highest(vector<int> &nums, int lo, int hi, int target) {
        if (lo > hi) {
            return -1;
        } else {
            auto mid = (hi + lo) / 2;
            if (nums.at(mid) == target) {
                if (mid < nums.size() - 1 && nums.at(mid + 1) == target) {
                    return recur_highest(nums, mid + 1, hi, target);
                } else {
                    return mid;
                }
            } 
            else if (target > nums.at(mid)) {
                return recur_highest(nums, mid + 1, hi, target);
            } else if (target < nums.at(mid)){
                return recur_highest(nums, lo, mid - 1, target);
            }
        }
        return -1;
    }
};