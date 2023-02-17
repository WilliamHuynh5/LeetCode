class Solution {
public:
    string interpret(string command) {
        vector<char> res;
        for (auto i = 0; i < command.size(); i++) {
            auto ch = command.at(i);
            if (ch == 'G') {
                res.push_back('G');
            } else if (ch == '(') {
                auto next_char = command.at(i + 1);
                if (next_char == ')') {
                    res.push_back('o');
                } else {
                    res.push_back('a');
                    res.push_back('l');
                }
            }
        }
        return string(res.begin(), res.end());
    }
};