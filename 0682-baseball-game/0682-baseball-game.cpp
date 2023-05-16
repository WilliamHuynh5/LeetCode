class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        
        for (auto i = 0; i < operations.size(); i++) {
            auto op = operations[i];
            if (op == "+") {
                auto score = stack.back() + stack[stack.size() - 2];
                stack.push_back(score);
            } else if (op == "D") {
                auto score = stack.back() * 2;
                stack.push_back(score);
            } else if (op == "C") {
                stack.pop_back();
            } else {
                stack.push_back(stoi(op));
            }
        }
        
        return accumulate(stack.begin(), stack.end(), 0);
    }
};