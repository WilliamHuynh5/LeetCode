class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        auto diff = arr[1] - arr[0];
        for (auto i = 0; i < arr.size() - 1; i++) {
            auto dist = arr[i + 1] - arr[i];
            if (dist != diff) {
                return false;
            }
        }
        return true;
    }
};