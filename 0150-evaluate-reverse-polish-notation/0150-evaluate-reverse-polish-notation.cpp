class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string> stk;
        
        for (auto token : tokens) {
            
            // If the token is a operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                
                // Pop two elements from the stack
                auto val2 = stoi(stk.top());
                stk.pop();
                auto val1 = stoi(stk.top());
                stk.pop();
                
                // Do the calculations, and push result back to stack
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

        // Top most value of the stack will be the result
        return stoi(stk.top());
    }
};