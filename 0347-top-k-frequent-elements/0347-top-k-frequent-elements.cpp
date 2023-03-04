class Solution {
public:
 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        map<int, vector<int>> m2;
        vector<int> res;
        
        for (auto elem : nums) {
            if (m.find(elem) != m.end()) {
                m[elem]++;
            } else {
                m[elem] = 1;
            }
        }
        
        set<int> freq;
        
        for (auto it = m.begin(); it != m.end(); it++) {
            freq.insert(it->second);
            m2[it->second].push_back(it->first);
        }
                
        auto i = 0;
        for (auto rIt=freq.rbegin(); rIt!=freq.rend(); ++rIt)   {
            auto elem = *rIt;
            if (i == k || res.size() == k) {break;}
            res.insert( res.end(), m2[elem].begin(), m2[elem].end() );
            i++;
        }
        
        return res;
    }
};