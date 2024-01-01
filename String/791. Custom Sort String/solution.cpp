class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        string retval;
        for (char c : order) {
            while (m[c]--) {
                retval += c;
            }
            m.erase(c);
        }

        for (auto it : m) {
            while (it.second--) {
                retval += it.first;
            }
        }
        return retval;
    }
};