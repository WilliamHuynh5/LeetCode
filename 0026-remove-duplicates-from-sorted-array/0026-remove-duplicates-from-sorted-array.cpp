class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int curr = nums.at(0);
        auto it = nums.begin();
        while (it != nums.end() - 1) {
            auto temp = it;
            temp++;
            if (*it == *temp) {
                nums.erase(temp, temp + 1);
            } else {
                it++;
            }
        }
        return nums.size();
    }
};