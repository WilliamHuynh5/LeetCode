class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto binary = std::bitset<32>(n).to_string();
        auto res = std::count(binary.begin(), binary.end(), '1');
        return res;
    }
};