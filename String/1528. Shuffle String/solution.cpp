class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;
        for (int i = 0; i < s.size(); i++) {
            int index = indices[i];
            res[index] = s[i];
        }
        
        return res;
    }
};