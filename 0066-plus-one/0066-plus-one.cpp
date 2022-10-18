class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto carryFlag = true;
        auto carry = 1;
        for (auto i = digits.size() - 1; i >= 0 && i < digits.size(); i--) {
            cout << i << "\n";
            auto bump = digits[i] + 1;
            carry = (bump == 10) ? 1 : 0;
            carry = (bump > 10) ? bump % 10 : carry;
            bump = bump % 10;
            digits[i] = bump;
            
            if (carry == 0) {
                cout << "hi" << "\n";
                break;
            }
        }
        
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
    
};