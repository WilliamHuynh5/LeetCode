class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        map<char, char> mp;
        
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        
        for (auto elem : s) {
            if (stk.size() > 0 && elem == mp[stk.top()]) {
                stk.pop();
            } else {
                stk.push(elem);
            }
        }

        if (stk.size() > 0) {
            return false;
        } 
        return true;
    }
};