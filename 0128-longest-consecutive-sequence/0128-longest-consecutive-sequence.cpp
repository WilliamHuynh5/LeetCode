class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;
        
        map<int, int> m;
        
        for (auto num : nums) {
            m[num] = 1;
        }
        
        auto prev = (*m.begin()).first;
        auto current = 1;
        auto longest = 1;
        
        for (auto pair : m) {
            if (prev + 1 == pair.first) {
                current++;
                longest = max(current, longest);
            } else {
                current = 1;
            }
            prev = pair.first;
        }
        return longest;
    }
};