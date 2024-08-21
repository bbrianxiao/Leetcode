class Solution {
    vector<string> retval;
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
public:
    void helper(string digits, int index, string temp) {
        if (index == digits.size() && !temp.empty()) retval.push_back(temp);
        for (auto c : letters[digits[index]]) {
            temp.push_back(c);
            helper(digits, index + 1, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        helper(digits, 0, "");
        return retval;
    }
};