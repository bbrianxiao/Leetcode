class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        int copy = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + (i/j));
                    if (j != 1) dp[i] = min(dp[i], dp[i/j] + j);
                }
            }
}
        return dp[n];
    }
};