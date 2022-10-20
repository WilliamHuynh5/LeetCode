class Solution {
public:
    int countOdds(int low, int high) {
        
        auto res = (high - low) / 2;
        if (low % 2 != 0 || high % 2 != 0){
            res++;
        }
        return res;
    }
};