class Solution {
public:
    string hashFunc(const string& str) {
        string hashVal;
        for (int i = 0; i < str.size() - 1; i++) {
            hashVal += ((str[i + 1] - str[i]) + 26) % 26 + 'a';
        }
        return hashVal;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> retval;
        unordered_map<string, vector<string>> m;
        for (auto& str : strings) {
            string hashVal = hashFunc(str);
            cout << hashVal << endl;
            m[hashVal].push_back(str);
        }

        for (auto it : m) {
            retval.push_back(it.second);
        }
        return retval;
    }
};