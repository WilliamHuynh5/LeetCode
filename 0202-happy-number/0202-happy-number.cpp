class Solution {
public:
    bool isHappy(int n) {
        auto vec = split(n);
        map<int, bool> m;
        while(true) {
            auto sum = calculate(vec);
            if (m.find(sum) != m.end()) break;
            if (sum == 1) {
                return true;
            } else {
                m[sum] = false;
                vec = split(sum);
            }
        }
        return false;
    }
    
    int calculate(vector<int> vec) {
        auto sum = 0;
        for (auto elem : vec) {
            sum+=(elem*elem);
        }
        return sum;
    }
    
    vector<int> split(int x) {
        vector<int> vec;
        while (x != 0) {
            vec.push_back(x % 10);
            x/=10;
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};