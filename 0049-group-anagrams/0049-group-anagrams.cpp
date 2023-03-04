class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> res;
        for (auto elem : strs) {
            auto temp = elem;
            sort(elem.begin(), elem.end());
            m[elem].push_back(temp);
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};