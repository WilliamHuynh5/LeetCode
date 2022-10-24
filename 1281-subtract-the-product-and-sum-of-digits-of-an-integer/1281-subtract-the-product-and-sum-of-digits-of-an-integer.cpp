class Solution {
public:
    int subtractProductAndSum(int n) {
        auto mul = 1;
        auto sum = 0;
        for (auto elem : to_string(n)) {
            auto num = elem - 48;
            mul*=num;
            sum+=num;
        }
        
        return mul - sum;
    }
};