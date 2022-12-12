class Solution {
public:
    int addDigits(int num) {
        auto res = 0;
        vector<int> vec = intToVec(num);
        
        while (vec.size() > 1) {
            res = accumulate(vec.begin(), vec.end(), 0);
            vec = intToVec(res);
        }
        
        res = accumulate(vec.begin(), vec.end(), 0);
        return res;
    }
    
    int vecToInt(vector<int> vec) {
        auto res = 0;
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
    
};