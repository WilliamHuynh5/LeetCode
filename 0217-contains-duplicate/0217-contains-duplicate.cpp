class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        map<int, int> m;
        
        for (auto elem : nums) {
            if (m.find(elem) != m.end()) {
                return true;
            } else {
                m[elem] = 1;
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