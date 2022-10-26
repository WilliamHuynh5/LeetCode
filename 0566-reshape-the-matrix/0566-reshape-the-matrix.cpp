class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        auto x = mat[0].size();
        auto y = mat.size();
        
        vector<int> merged;
        
        for (auto subArr : mat) {
            for (auto elem : subArr) {
                merged.push_back(elem);
            }
        }
        
        if (r * c != merged.size()) {
            return mat;
        }
        
        vector<vector<int>> res;
        auto count = 0;
        vector<int> temp;
        
        auto i = 0;
        while (i < merged.size()) {
            if (count < c) {
                temp.push_back(merged[i]);
                i++;
            } 
            if (count == c || c == 1){
                res.push_back(temp);
                temp.clear();
                count = 0;
                continue;
            }
            count++;
            
        }

        if (c != 1) { 
            res.push_back(temp);
        }
        return res;
    }
};