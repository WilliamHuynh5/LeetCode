class Solution {
public:
    int lengthOfLastWord(string s) {
        
        auto inWord = false;
        vector<char> temp;
        for (auto i = s.length() - 1; i >= 0 && i < s.size(); i--) {
            if (!isspace(s.at(i))) {
                inWord = true;
                temp.push_back(s.at(i));
            } else if (inWord == true) {
                break;
            }
        }
        cout << "hi";
        return temp.size();
    }
};