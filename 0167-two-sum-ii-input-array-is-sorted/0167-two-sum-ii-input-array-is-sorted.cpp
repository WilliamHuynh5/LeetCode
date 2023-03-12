class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size() - 1;
        
        while (numbers.at(lo) + numbers.at(hi) != target) {
            if (numbers.at(lo) + numbers.at(hi) < target) {
                lo++;
            } else {
                hi--;
            }
        }
        return {lo + 1, hi + 1};
    }
    

    
};