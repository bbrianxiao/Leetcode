class Solution {
public:
    int calculate(string s) {
        int lastNum = 0;
        int result = 0;
        int currNum = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            char currChar = s[i];
            if (isdigit(currChar)) {
                currNum = currNum * 10 + (currChar - '0');
            }
            if (!isdigit(currChar) && !iswspace(currChar) || i == s.size() - 1) {
                if (sign == '+') {
                    result += lastNum;
                    lastNum = currNum;
                } else if (sign == '-') {
                    result += lastNum;
                    lastNum = -currNum;
                } else if (sign == '*') {
                    lastNum = lastNum * currNum;
                } else if (sign == '/') {
                    lastNum = lastNum / currNum;
                }
                sign = currChar;
                currNum = 0;
            }
        }
        return result + lastNum;
    }
};