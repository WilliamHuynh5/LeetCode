class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        auto sum = 0.0;
        for (auto i = 1; i < salary.size() - 1; i++){
            sum+=salary.at(i);
        }
        
        return sum / ((salary.size() - 2) * 1.0);
    }
};