class Solution {
public:
    int maxArea(vector<int>& height) {
        auto lp = 0;
        auto rp = height.size() - 1;
        auto curr_max = 0;
        
        while (lp < rp) {
            
            auto area = min(height[lp], height[rp]) * (rp - lp);
            
            if (area > curr_max) {
                curr_max = area;
            }
            
            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }
        
        return curr_max;
    }
    
};