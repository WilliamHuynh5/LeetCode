class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        auto numDiff = 0;
        vector<int> vec;
        for (auto i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) continue;
            if (++numDiff > 2) return false;
            
            vec.push_back(i);
        }
        
        if (numDiff < 2) return false;
        
        auto charA = s1.at(vec[0]);
        auto charB = s1.at(vec[1]);
        
        s1.at(vec[0]) = charB;
        s1.at(vec[1]) = charA;
        
        return s1 == s2;
    }
};