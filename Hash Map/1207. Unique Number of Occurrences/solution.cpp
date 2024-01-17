class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto c : arr) {
            m[c]++;
        }
        unordered_set<int> s;
        for (auto n : m) {
            s.insert(n.second);
        }

        return s.size() == m.size();

    }
};