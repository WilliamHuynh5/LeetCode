class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [] (string a, string b){
            return a.size() < b.size();
        });

        auto max = strs.at(0).size();
        string res;
        for (auto i = 0; i  < max; i++) {
            auto ch = strs.at(0).at(i);
            
            auto valid = true;
            for (auto elem : strs) {
                if (elem == strs.at(0)) continue;
                if(elem.at(i) != ch){
                    valid = false;
                }
            }
            if (valid == true) {
                res+=ch;
            } else {
                return res;
            }
        }
        return res;
    }
};