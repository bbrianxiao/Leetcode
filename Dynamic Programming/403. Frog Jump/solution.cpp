class Solution {
    int dp[2001][2001];
    unordered_map<int, int> m;
public:
    bool canCross(vector<int>& stones) {
        dp[0][0] = 1;

        for (int i = 0; i < stones.size(); i++) {
            m[stones[i]] = i;
        }
        
        for (int i = 0; i < stones.size(); i++) {
            for (int j = 0; j <= stones.size(); j++) {
                if (dp[i][j]) {
                    if (m[stones[i] + j]) {
                        dp[m[stones[i] + j]][j] = 1;
                    }
                    if (m[stones[i] + j + 1]) {
                        dp[m[stones[i] + j + 1]][j + 1] = 1;
                    }
                    if (m[stones[i] + j - 1]) {
                        dp[m[stones[i] + j - 1]][j - 1] = 1;
                    }
                }
            }
        }
        for (int i = 0; i <= stones.size(); i++) {
            if (dp[stones.size() - 1][i]) {
                return true;
            }
        }
        return false;
    }
};