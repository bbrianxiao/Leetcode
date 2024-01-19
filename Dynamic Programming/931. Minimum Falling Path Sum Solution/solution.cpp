class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j] = matrix[i][j];
                } else {
                    int mini = INT_MAX;
                    if (j == 0) {
                        mini = min(dp[i - 1][j], dp[i - 1][j + 1]);
                    } else if (j == n - 1) {
                        mini = min(dp[i - 1][j], dp[i - 1][j - 1]);
                    } else {
                        mini = min(dp[i - 1][j], dp[i - 1][j - 1]);
                        mini = min(mini, dp[i - 1][j + 1]);
                    }
                    dp[i][j] = mini + matrix[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j];
            }
            cout << endl;
        }

        int smallest = INT_MAX;
        for (int i = 0; i < n; i++) {
            smallest = min(dp[n-1][i], smallest);
        }
        return smallest;

    }
};