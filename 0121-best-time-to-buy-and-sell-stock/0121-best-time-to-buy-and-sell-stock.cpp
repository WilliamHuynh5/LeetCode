class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto lowest = INT_MAX;
        auto profit = 0;

        for (auto elem : prices) {
            if (elem < lowest) {
                lowest = elem;
            }
            if (elem > lowest) {
                auto temp_profit = elem - lowest;
                if (temp_profit > profit) {
                    profit = temp_profit;
                }
            }
        }
        return profit;
    }
};