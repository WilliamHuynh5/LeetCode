class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        auto currLow = INT_MAX;
        auto res = -1;
        
        for (auto i = 0; i < points.size(); i++) {
            auto point = points.at(i);
            if (point[0] != x && point[1] != y) {
                continue;
            }
            auto distance = abs(x - point[0]) + abs(y - point[1]);
            if(distance < currLow) {
                currLow = distance;
                res = i;
            }
        }
        
        return res;
    }
};