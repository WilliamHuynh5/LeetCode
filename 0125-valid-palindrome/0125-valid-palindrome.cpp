class Solution {
public:
    bool isPalindrome(string s) {
        auto ss = santiser(s);
        auto tempss = ss;
        reverse(ss.begin(), ss.end());
        cout << tempss << " " << ss << "\n";
        if (tempss == ss) {
            return true;
        }
        return false;
    }
    
    string santiser(string s) {
        string res = "";
        for (auto ch : s) {
            if (isalpha(ch) || isdigit(ch)) {
                res+=tolower(ch);
            }
        } 
        return res;
    }
};