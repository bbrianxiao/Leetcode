class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> count;
        for (auto& word : words) {
            count[word]++;
        }
        int retval = 0;
        bool isSingle = false;
        for (auto it : count) {
            string p = it.first;
            if (p[0] == p[1]) {
                if (!isSingle) {
                    retval += count[p];
                    isSingle = count[p] % 2 == 1;
                } else {
                    retval += count[p] % 2 == 1 ? count[p] - 1 : count[p];
                }
            } else {
                reverse(p.begin(), p.end());
                if (count.find(p) != count.end()) {
                    retval += min(count[it.first], count[p]);
                }
            }
        }
        return retval * 2;
    }
};