class Solution {
    vector<pair<int, int>> dir {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != 1) return dp[i][j];
        int n = matrix.size();
        int m = matrix[0].size();
        for (auto d : dir) {
            int nextX = i + d.first;
            int nextY = j + d.second;
            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
            if (matrix[nextX][nextY] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + dfs(matrix, dp, nextX, nextY));
            }
        }
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        // dp[i][j]: longest increasing path in matrxi starting from i, j;
        vector<vector<int>> dp (n, vector<int>(m, 1));
        int maxPath = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxPath = max(maxPath, dfs(matrix, dp, i, j));
            }
        }
        return maxPath;
    }
};