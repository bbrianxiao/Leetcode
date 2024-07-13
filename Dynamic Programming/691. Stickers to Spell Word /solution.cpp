class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int sz = target.size();
        int n = (1 << sz);
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INT_MAX) continue;

            for (auto str : stickers) {
                int j = findNextState(str, target, i);
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n-1] == INT_MAX ? -1 : dp[n-1];
    }

    int findNextState(const string& str, const string target, int currState) {
        int n = target.size();
        for (auto& ch : str) {
            for (int k = 0; k < n; k++) {
                if (((currState >> k)&1) == 0 && target[k] == ch) {
                    currState += (1 << k);
                    break;
                }
            }
        }
        return currState;
    }
};