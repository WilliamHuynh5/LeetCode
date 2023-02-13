class Solution {
public:
    int smallestEvenMultiple(int n) {
        for (auto i = n; i < INT_MAX; i++) {
            if (i % n == 0 && i % 2 == 0) {
                return i;
            }
        }
        return 0;
    }
};