class Solution {
public:
    bool helper(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return helper(s, start + 1, end) || helper(s, start, end - 1);
            } else {
                start++;
                end--;
            }
        }
        return true;
    }
};
