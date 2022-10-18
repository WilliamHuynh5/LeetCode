class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for (auto elem : s) {
            if (elem == '(' || elem == '[' || elem == '{'){
                stk.push(elem);
            } else {
                auto top = stk.top();
                
                if (stk.empty() || (top == '(' && elem != ')') || (top == '[' && elem != ']') || (top == '{' && elem != '}')) {
                    return false;
                }
                stk.pop();
            }
        }
        
        if (stk.empty()){
            return true;
        }
        return false;
    }
};