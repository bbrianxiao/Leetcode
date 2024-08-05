class Solution {
    long long dp[201][201];
    map<pair<int, int>, long long> mp;
public:
    long long dfs(int m, int n, vector<vector<int>>& prices) {
        if (dp[m][n] != -1) return dp[m][n];

        long long ans = mp[{m,n}]; 

        for (int i = 1; i <= m / 2; i++) {
            ans = max(ans, dfs(i, n, prices) + dfs(m - i, n, prices));
        }

        for (int i = 1; i <= n / 2; i++) {
            ans = max(ans, dfs(m, i, prices) + dfs(m, n - i, prices));
        }

        return dp[m][n] = ans;
    }

    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        for (int i = 0; i < 201; ++i) {
            for (int j = 0; j < 201; ++j) {
                dp[i][j] = -1;
            }
        }

        for (int i = 0; i < prices.size(); i++) {
            mp[{prices[i][0], prices[i][1]}] = prices[i][2];
        }
        return dfs(m, n, prices);
    }
};