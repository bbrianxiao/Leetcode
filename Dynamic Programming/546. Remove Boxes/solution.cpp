class Solution {
    int dp[101][101][101];
public:
    int removeBoxes(vector<int>& boxes) {
        return dfs(boxes, 0, boxes.size() - 1, 0);
    }

    int dfs(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        if (dp[l][r][k] != 0) {
            return dp[l][r][k];
        }
        dp[l][r][k] = dfs(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0));
            }
        }

        return dp[l][r][k];
    }
};