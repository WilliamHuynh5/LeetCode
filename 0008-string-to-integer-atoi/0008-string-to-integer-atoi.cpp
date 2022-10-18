class Solution {
public:
    int myAtoi(string s) {
        auto positive = true;
        vector<char> rawNumber;
        auto leading = true;
        auto changed = false;
        for (auto elem : s) {
            if (isspace(elem)) {
                if (leading == true && changed == false) {
                    continue;
                } else {
                    break;
                }
            } else if (elem == '-') {
                if (changed == true) {
                    break;
                } 
                positive = false;
                changed = true;
            } else if (elem == '+') {
                if (changed == true) {
                    break;
                }
                positive = true;
                changed = true;
            } else if (!isdigit(elem)) {
                break;
            } else {
                if (changed == false) {
                    changed = true;
                }
                rawNumber.push_back(elem);
                leading = false;
            }
        }
        
        cout << string(rawNumber.begin(), rawNumber.end());
        
        if (rawNumber.size() == 0) {
            return 0;
        }
        long long res = 0;
        
        for (auto elem : rawNumber) {
            res = res * 10 + (elem - 48);
            if (res > INT_MAX && positive == true) {
                return INT_MAX;
            } else if (res > INT_MAX && positive == false) {
                return INT_MIN;
            }
        }
        

        if (positive == true) {
            res = abs(res);
        } else {
            res = res * -1;
        }
        
        return (int)res;
    }
};