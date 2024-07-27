class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        s = '/' + s;
        p = '/' + p;

        dp[0][0] = true;
        for (int j = 2; j <=m; j++) {
            if (p[j] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (isalpha(p[j])) {
                    dp[i][j] = dp[i-1][j-1] && s[i]==p[j];
                } else if (p[j] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j] == '*') {
                    dp[i][j] = ((s[i] == p[j-1] || p[j-1] == '.') && (dp[i][j-1] || dp[i-1][j])) || dp[i][j-2];
                }
            }
        }

        return dp[n][m];

    }
};