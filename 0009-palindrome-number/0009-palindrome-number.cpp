class Solution {
public:
    bool isPalindrome(int x) {
        auto str = to_string(x);
        auto temp = str;
        reverse(str.begin(), str.end());
        if (str == temp) {
            return true;
        }
        return false;
    }
};