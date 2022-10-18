class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> seen;
        vector<int> sizes;
        
        if (s.size() == 1) {
            return 1;
        }
        
        
        for (auto i = 0; i < s.size(); i++) {
            if (seen.size() == 0) {
                seen.push_back(s[i]);
            }
            
            for (auto j = i + 1; j < s.size(); j++) {
                if (count(seen.begin(), seen.end(), s[j])) {
                    sizes.push_back(seen.size());
                    seen.clear();
                    break;
                }    
                seen.push_back(s[j]);
            }
            
        }

        sizes.push_back(seen.size());
        sort(sizes.begin(), sizes.end(), greater<int>());
        return sizes.at(0);
    }
};