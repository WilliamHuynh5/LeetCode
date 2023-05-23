class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // Intialise right pointer, left pointer and current max
        auto lp = 0;
        auto rp = height.size() - 1;
        auto curr_max = 0;
        
        // Whilst the lp < rp
        while (lp < rp) {
            
            // Calculate area
            auto area = min(height[lp], height[rp]) * (rp - lp);
            
            // Set the current max
            if (area > curr_max) {
                curr_max = area;
            }
            
            // Follow a greedy approach by trying to maximise the value of the lp and rp
            // Move the pointer depending on whether the lp value is less than the rp value and vice versa
            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }
        
        return curr_max;
    }
    
};