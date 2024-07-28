class Solution {
    int dp[202][202];
public:
    int getMoneyAmount(int n) {
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k-1], dp[k+1][j])); 
                }
            }
        }

        return dp[1][n];
    }
};  
