class Solution {
public:
    int maxArea(vector<int>& height) {
        
        auto start = height.begin();
        auto end = height.end();
        end--;
        vector<int> res;
        auto currHigh = -1;
        
        while (start != height.end() && end >= height.begin()) {
            
            auto height = (*start < *end) ? *start : *end;
            auto length = distance(start, end);

            if (height * length > currHigh) {
                currHigh = height * length;
            }
            
            if (*start < *end) {
                start++;
            } else{
                end--;
            }
        }
        return currHigh;
    }
    
};