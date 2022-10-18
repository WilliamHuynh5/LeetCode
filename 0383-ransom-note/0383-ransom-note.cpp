class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for (auto elem : ransomNote) {
            if (m.find(elem) != m.end()) {
                m[elem]++;
            } else {
                m[elem] = 1;
            }
        }
        
        for (auto elem : magazine) {
            if (m.find(elem) != m.end()) {
                m[elem]--; 
            }
        }
        
        for (auto elem : m) {
            if (elem.second > 0) {
                return false;
            }
        }
        return true;
        
    }
};