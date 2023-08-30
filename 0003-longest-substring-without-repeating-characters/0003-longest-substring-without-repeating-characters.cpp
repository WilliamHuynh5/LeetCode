class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        vector<char> substring;
        int i = 0;
        int res = 0;
        while (i < s.size()) {
            char ch = s[i];
            cout << ch << "\n";
            // If hasn't been seen
            if (seen.find(ch) == seen.end()) {
                cout << "bye\n";
                seen.insert(ch);
                substring.push_back(ch);
                i++;
            } else {
                res = std::max(res, static_cast<int>(substring.size()));
                // Remove all characters before and including the seen character
                while (!substring.empty() && substring.front() != ch) {
                    seen.erase(substring.front());
                    substring.erase(substring.begin());
                }
                if (!substring.empty()) {
                    seen.erase(substring.front());
                    substring.erase(substring.begin());
                }
            }
        } 
        res = std::max(res, static_cast<int>(substring.size()));
        return res;
    }
};
                