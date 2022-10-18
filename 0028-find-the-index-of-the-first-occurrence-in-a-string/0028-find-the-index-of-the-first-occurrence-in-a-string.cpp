class Solution {
public:
    int strStr(string haystack, string needle) {
            
        if (needle.size() > haystack.size()) {
            return -1;
        }
        
        auto index = 0;
        auto len = needle.size();
        for (auto i = 0; i < haystack.size(); i++) {
            auto valid = true;
            if (haystack.at(i) == needle.at(0)) {
                auto k = 0;
                for (auto j = i; k < len; j++, k++) {
                    if (j >= haystack.size()){
                        valid = false;
                        break;
                    }
                    if (haystack.at(j) != needle.at(k)) {
                        valid = false;
                    }
                }
                if (valid == true) return i;
            }
        }
                        
        return -1;
    }
};