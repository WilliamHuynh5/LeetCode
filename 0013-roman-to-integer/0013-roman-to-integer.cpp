class Solution {
public:

    
    int romanToInt(string s) {
        auto res = 0;
        
        for (auto i = 0; i < s.size(); i++) {
            auto currChar = s.at(i);
            auto nextChar = '\0';
            
            if (i < s.size()) {
                auto x = currChar;
                auto y = s[i + 1];
                if (x == 'I' && (y == 'V' || y == 'X')) {
                    nextChar = y;
                }
                if (x == 'X' && (y == 'L' || y == 'C')) {
                    nextChar = y;
                }
                if (x == 'C' && (y == 'D' || y == 'M')) {
                    nextChar = y;
                }
        
            }
            
            cout << "INC: " << i << " " << s.at(i) << "\n";
            cout << "RES: " << res << "\n";
            cout << "SUB: " << getSubtraction(currChar, nextChar) << "\n\n";
            
            res = res + getSubtraction(currChar, nextChar);
            if (nextChar != '\0'){
                cout << "TRI\n"; 
                i++;
            }
        }
        
        return res;
    }
    
    int getSubtraction(char x, char y) {
        std::map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        if (x == 'I' && (y == 'V' || y == 'X')) {
            return m[y] - m[x];
        }
        if (x == 'X' && (y == 'L' || y == 'C')) {
            return m[y] - m[x];
        }
        if (x == 'C' && (y == 'D' || y == 'M')) {
            return m[y] - m[x];
        }
        
        return m[x];
    }
};