class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        vector<string> ops = {"+", "-", "*", "/"};
        stack<string> stk;
        
        for (auto token : tokens) {
            cout << token << "\n";
            // If the token is a operator
            if (find(ops.begin(), ops.end(), token) != ops.end()) {
                auto val2 = stoi(stk.top());
                stk.pop();
                auto val1 = stoi(stk.top());
                stk.pop();
                
                if (token == "+") {
                    stk.push(to_string(val1 + val2));
                }
                if (token == "-") {
                    stk.push(to_string(val1 - val2));
                }
                if (token == "*") {
                    stk.push(to_string(val1 * val2));
                }
                if (token == "/") {
                    stk.push(to_string(val1 / val2));
                }
            } else {
                stk.push(token);
            }
        }

        return stoi(stk.top());
    }
};