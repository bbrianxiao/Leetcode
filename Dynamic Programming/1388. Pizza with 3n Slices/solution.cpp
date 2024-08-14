class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int pick = n / 3;

        vector<vector<int>> dp1(n, vector<int>(pick + 1, 0));
        vector<vector<int>> dp2(n, vector<int>(pick + 1, 0));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j <= pick; j++) {
                if (i == 0) {
                    dp1[i][j] = slices[i];
                } else if (i == 1) {
                    dp1[i][j] = max(dp1[i-1][j], slices[i]);
                } else {
                    dp1[i][j] = max(dp1[i-1][j], dp1[i-2][j-1] + slices[i]);
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= pick; j++) {
                if (i == 1) {
                    dp2[i][j] = slices[i];
                } else if (i == 2) {
                    dp2[i][j] = max(dp2[i-1][j], slices[i]);
                } else {
                    dp2[i][j] = max(dp2[i-1][j], dp2[i-2][j-1] + slices[i]);
                }
            }
        }

        return max(dp1[n-2][pick], dp2[n-1][pick]);
    }
};
