class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        
        
        for (auto ch : s) {
            // If it's an opening bracket
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if (!stk.empty() && m[stk.top()] == ch) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        
        return stk.empty();
    }
};