class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // If size is 0, return 0
        if (nums.size() == 0) return 0;
        
        // Initialise the map where the keys are elements in nums
        map<int, int> m;
        for (auto num : nums) {
            m[num] = 1;
        }
        
        // Two pointers technique, compare the prev with the current key
        auto prev = (*m.begin()).first;
        
        // current streak and longest streak
        auto current = 1;
        auto longest = 1;
        
        // Iterate through keys in the map
        for (auto pair : m) {
            // Use two pointers technique to keep track of current key and previous key
            // If key differs by 1, then increment current
            if (prev + 1 == pair.first) {
                current++;
                longest = max(current, longest);
            } else {
                current = 1;
            }
            // Keep track of the previous key
            prev = pair.first;
        }
        return longest;
    }
};