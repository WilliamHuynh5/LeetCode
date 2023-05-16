class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        // Uses a stack to store the score records
        vector<int> stack;
        
        // Iterate through all the operations
        for (auto op : operations) {
            if (op == "+") {
                // Sum the last and second last value in the stack
                auto score = stack.back() + stack[stack.size() - 2];
                stack.push_back(score);
            } else if (op == "D") {
                // Double the last value in the stack
                auto score = stack.back() * 2;
                stack.push_back(score);
            } else if (op == "C") {
                // Remove the last value in the stack
                stack.pop_back();
            } else {
                stack.push_back(stoi(op));
            }
        }
        
        // Sum of the stack
        return accumulate(stack.begin(), stack.end(), 0);
    }
};