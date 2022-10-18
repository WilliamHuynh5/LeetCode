class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string build;
        recur(res, build, n, 0);
        return res;
    }
    
    void recur(vector<string> &res, string build, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(build);
            return;
        } else {
            
            if (open > 0) {
                recur(res, build + "(", open - 1, close + 1);
            }
            if (close > 0) {
                recur (res, build + ")", open, close - 1);
            }
        }
    }
    

};