class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 2));
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (m.count(arr[i] + arr[j])) {
                    dp[j][m[arr[i] + arr[j]]] = max(dp[j][m[arr[i] + arr[j]]], dp[i][j] + 1);
                }
            }
        }

        int retval = 2;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                retval = max(retval, dp[i][j]);
            }
        }
        
        return retval == 2 ? 0 : retval;
    }
};