class Solution {
public:
    int addDigits(int num) {
        
        auto res = 0;
        
        vector<int> vec = intToVec(num);
        
        while (vec.size() > 1) {
            res = getVecSum(vec);
            vec = intToVec(res);
        }
        res = getVecSum(vec);
        return res;
    }
    
    
    int vecToInt(vector<int> vec) {
        int res = 0;
        for (auto dig : vec) {
            res = res * 10 + dig;
        }
        return res;
    }
    
    vector<int> intToVec(int num) {
        vector<int> vec;
        while (num != 0) {
            vec.push_back(num % 10);
            num/=10;
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
    
    int getVecSum(vector<int> vec) {
        return accumulate(vec.begin(), vec.end(), 0);
    }
};