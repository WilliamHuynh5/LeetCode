class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        
        for (auto elem : nums) {
            if (m.count(elem)) {
                m[elem]++;
            } else {
                m[elem] = 1;
            }
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                return it->first;
            }
        }
        return 0;
    }
};