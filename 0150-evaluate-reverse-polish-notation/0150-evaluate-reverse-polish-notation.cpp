class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk;
        
        for (auto token : tokens) {
            
            // If the token is a operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                
                // Pop two elements from the stack
                auto val2 = stk.top();
                stk.pop();
                auto val1 = stk.top();
                stk.pop();
                
                // Do the calculations, and push result back to stack
                if (token == "+") {
                    stk.push(val1 + val2);
                }
                if (token == "-") {
                    stk.push((val1 - val2));
                }
                if (token == "*") {
                    stk.push(val1 * val2);
                }
                if (token == "/") {
                    stk.push(val1 / val2);
                }
            } else {
                stk.push(stoi(token));
            }
        }

        // Top most value of the stack will be the result
        return stk.top();
    }
};