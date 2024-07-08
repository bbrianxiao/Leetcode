class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0, closing = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                opening++;
            } else {
                if (opening == 0) {
                    closing++;
                } else {
                    opening--;
                }
            }
        }
        return opening + closing;
    }
};