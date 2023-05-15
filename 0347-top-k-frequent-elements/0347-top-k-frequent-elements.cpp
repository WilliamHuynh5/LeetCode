class Solution {
public:
 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto elem : nums) {
            if (freq.find(elem) != freq.end()) {
                freq[elem]++;
            } else {
                freq[elem] = 1;
            }
        }
        
        vector<int> bucket[nums.size() + 1];
        for (auto i = 0; i < nums.size(); i++) {
            vector<int> v;
            bucket[i] = v;
        }

        auto max = -1;
        for (auto elem : freq) {   
            bucket[elem.second].push_back(elem.first);
            if (elem.second > max) {
                max = elem.second;
            }
        } 
        
        auto iter = max - k;
        if (max < k) {
            iter = -1;
        }
        cout << max << "\n";
        cout << iter << "\n";
        
        for (auto elem : bucket) {
            for (auto e : elem) {
                cout << e << " ";
            }
            cout << "\n";
        }
        //cout << "\n";
        
        vector<int> res;
        
        while (res.size() != k) {
            res.insert(res.end(), bucket[max].begin(), bucket[max].end());
            max--;
        }
        
        // for (auto i = max; i > 0; i--) {
        //     res.insert(res.end(), bucket[i].begin(), bucket[i].end());
        //     if (res.size() == k) {
        //         break;
        //     }
        // }
        return res;
    }
};