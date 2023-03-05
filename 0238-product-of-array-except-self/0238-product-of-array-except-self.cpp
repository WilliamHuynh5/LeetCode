class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = nums;
        vector<int> suffix = nums;
        auto len = nums.size();
        
        for (int i = 1; i < len - 1; i++) {
            prefix[i] *= prefix[i-1];
            suffix[len - i - 1] *= suffix[len - i];
        }
        
        for (auto elem : prefix) {
            cout << elem << "\n";
        }
        cout << "===========\n";
        for (auto elem : suffix) {
            cout << elem << "\n";
        }
        
        nums[0] = suffix[1];
        nums[len - 1] = prefix[len - 2];
        
        for (auto i = 1; i < len - 1; i++) {
            nums[i] = prefix[i - 1] * suffix[i + 1];
        }
        
        return nums;
    }
};