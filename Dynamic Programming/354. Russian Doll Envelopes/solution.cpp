class Solution {
public:
    static bool mySort(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 1) return 1;
        sort(envelopes.begin(), envelopes.end(), mySort);
        vector<int> dp;
        for (int i = 0; i < n; i++) {
            if (dp.empty()) {
                dp.push_back(envelopes[i][1]);
            } else {
                if (envelopes[i][1] > dp.back()) {
                    dp.push_back(envelopes[i][1]);
                } else {
                    auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                    *it = envelopes[i][1];
                }
            }
        }
        return dp.size();

    }
};