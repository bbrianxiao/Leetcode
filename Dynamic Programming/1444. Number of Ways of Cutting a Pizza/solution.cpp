class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int MOD = 1e9 + 7;
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                prefix[i][j] = (pizza[i][j] == 'A') + prefix[i + 1][j] + prefix[i][j + 1] - prefix[i + 1][j + 1];
            }
        }

        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, 0)));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (prefix[i][j] > 0) dp[0][i][j] = 1;
            }
        }

        for (int cut = 1; cut < k; ++cut) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int x = i + 1; x < m; ++x) {
                        if (prefix[i][j] - prefix[x][j] > 0) {
                            dp[cut][i][j] = (dp[cut][i][j] + dp[cut - 1][x][j]) % MOD;
                        }
                    }
                    for (int y = j + 1; y < n; ++y) {
                        if (prefix[i][j] - prefix[i][y] > 0) {
                            dp[cut][i][j] = (dp[cut][i][j] + dp[cut - 1][i][y]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[k - 1][0][0];
    }
};
