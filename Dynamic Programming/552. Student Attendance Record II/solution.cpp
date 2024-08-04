class Solution {
    const int mod = 1000000007;
public:
    int checkRecord(int n) {
        if (n == 0) return 0;
        if (n == 1) return 3;
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        dp[1][0][0] = 1;
        dp[1][1][0] = 1;
        dp[1][0][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % mod;
                    if (j > 0) {
                        dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][k]) % mod;
                    }
                    if (k < 2) {
                        dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i - 1][j][k]) % mod;
                    }
                }
            }
        }

        int total = 0;
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 2; j++) {
                total = (total +  dp[n][i][j]) % mod;
            }
        }
        return total;
    }
};