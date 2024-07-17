class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.size();
        
        while (i < n && isspace(s[i])) {
            ++i;
        }
        
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            ++i;
        }
        
        bool isNumeric = false;
        bool isExponent = false;
        bool isDecimal = false;
        
        while (i < n) {
            if (isdigit(s[i])) {
                isNumeric = true;
            } else if (s[i] == '.') {
                if (isDecimal || isExponent) {
                    return false;
                }
                isDecimal = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (isExponent || !isNumeric) {
                    return false;
                }
                isExponent = true;
                isNumeric = false;  // Reset for the exponent part
            } else if (s[i] == '+' || s[i] == '-') {
                if (s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else {
                break;
            }
            ++i;
        }
        
        while (i < n && isspace(s[i])) {
            ++i;
        }
        
        return isNumeric && i == n;
    }
};