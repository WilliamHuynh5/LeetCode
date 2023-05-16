class Solution {
public:
 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Initialise frequency table 
        map<int, int> freq;
        for (auto elem : nums) {
            freq[elem]++;
        }
        
        // Initialise bucket
        vector<int> bucket[nums.size() + 1];
        for (auto i = 0; i < nums.size(); i++) {
            vector<int> v;
            bucket[i] = v;
        }

        // Sort into the bucket
        auto max = -1;
        for (auto elem : freq) {   
            bucket[elem.second].push_back(elem.first);
            if (elem.second > max) {
                max = elem.second;
            }
        } 
        
        // Get the top K elements
        vector<int> res;
        while (res.size() != k) {
            res.insert(res.end(), bucket[max].begin(), bucket[max].end());
            max--;
        }
        
        return res;
    }
};