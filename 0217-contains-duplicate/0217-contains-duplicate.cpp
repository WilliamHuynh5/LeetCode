class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    // Two methods
    // 1. use a hashmap and check if key exists O(n)
    // 2. sort array and iterate through 0(nlogn) + O(n);
    map<int, bool> m;
        for (auto num : nums) {
            // If num doesn't exist in the map
            if (m.find(num) == m.end()) {
                m[num] = true;
            } 
            // The number exists, therefore there is a duplicate!
            else {
                return true;
            }
        }
        return false;
    }
};

/*
    // Sorting the vector. Will take O(nlogn) time as it uses a merge sort
    sort(nums.begin(), nums.end());

    // Iterate through the vector and keep a copy of the previous element. 
    // If the previous element matches the current element, there is a duplicate.
    // Runs in O(n) time

    for (auto i = 1; i < nums.size(); i++) {
        if (nums.at(i - 1) == nums.at(i)) {
            return true;
        }
    }
    return false;
*/