class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if (word.size() < abbr.size()) return false;
        int n = word.size();
        int abbr_size = 0;
        for (int i = 0; i < abbr.size();) {
            if (abbr[i] == '0') {
                return false;
            }
            if (isdigit(abbr[i])) {
                int j = i;
                while (i < word.size() && isdigit(abbr[i])) {
                    i++;
                }
                abbr_size += stoi(abbr.substr(j, i - j));
            } else {
                if (word[abbr_size] != abbr[i]) {
                    return false;
                } else {
                    abbr_size++;
                    i++;
                }
            }
        }
        return n == abbr_size;
    }
};
