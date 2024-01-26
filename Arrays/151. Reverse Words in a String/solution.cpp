class Solution {
public:
    string reverseWords(string s) {
        stringstream iss {s};
        string result;
        string word;
        iss >> result;
        while (iss >> word) {
            result = word + ' ' + result;
        }

        return result;
    }
};