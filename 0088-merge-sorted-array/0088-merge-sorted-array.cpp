class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto idx = nums1.size() - n;
        
        for (auto elem : nums2) {
            nums1[idx] = elem;
            idx++;
        }
        sort(nums1.begin(), nums1.end());
    }
};