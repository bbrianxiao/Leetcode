using ll = long long;

class Solution {
    const int MOD = 1000000007;
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp (n + 1, vector<int> (5, 0));
        // 'a': 0 'e': 1 'i': 2 'o': 3 'u': 4
        for (int i = 0; i < 5; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = ((ll) dp[i - 1][1] + (ll) dp[i - 1][2] + (ll) dp[i - 1][4]) % MOD; // 'a'
            dp[i][1] = ((ll) dp[i - 1][0] + (ll) dp[i - 1][2]) % MOD; // 'e' 
            dp[i][2] = ((ll) dp[i - 1][1] + (ll) dp[i - 1][3]) % MOD; // 'i'
            dp[i][3] = ((ll) dp[i - 1][2]) % MOD; // 'o'
            dp[i][4] = ((ll) dp[i - 1][2] + (ll) dp[i - 1][3]) % MOD; // 'u'
        }

        int retval = 0;
        for (int i = 0; i < 5; i++) {
            retval = (retval + dp[n][i]) % MOD;
        }
        return retval;
    }
};
