class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while (j < s.size()) {
            char c = s[j];
            m[c]++;
            j++;
            while (m[c] > 1) {
                char d = s[i++];
                m[d]--;
            }
            maxLen = max(maxLen, j - i);
        }
        return maxLen;
    }
};