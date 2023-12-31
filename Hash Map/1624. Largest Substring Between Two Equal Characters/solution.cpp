class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int retval = -1;
        vector<int> v (26, -1);
        int maxlen = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (v[c - 'a'] == -1) {
                v[c - 'a'] = i;
            } else {
                maxlen = max(maxlen, i - v[c - 'a'] - 1);
            }
        }
        return maxlen;
    }
};