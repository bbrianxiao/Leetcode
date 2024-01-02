class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_map<int, int> m;
        for (auto i : nums) {
            m[i]++;
            if (m[i] > results.size()) {
                results.push_back({});
            }
            results[m[i] - 1].push_back(i);
        }
        return results;

    }
};