class Solution {
    const int MOD = 1000000007;
public:
    int decode1(char c1) {
        if (c1 == '*') {
            return 9;
        }
        if (c1 == '0') {
            return 0;
        }
        return 1;
    }

    int decode(char c1, char c2) {
        if (c1 == '*' && c2 == '*') {
            return 15;
        }
        if (c1 == '*' && c2 == '0') {
            return 2;
        }
        if (c1 == '*') {
            return c2 <= '6' ? 2 : 1;
        }
        if (c1 == '1' && c2 == '*') {
            return 9;
        }
        if (c1 == '1' && c2 != '*') {
            return 1;
        }
        if (c1 == '2' && c2 == '*') {
            return 6;
        }
        if (c1 == '2' && c2 != '*') {
            return c2 <= '6' ? 1 : 0;
        }
        return 0;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp (n + 1, 0);
        dp[0] = 1;
        dp[1] = decode1(s[0]);
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i] + (long long) dp[i - 1] * decode1(s[i - 1])) % MOD;
            dp[i] = (dp[i] + (long long) dp[i - 2] * decode(s[i - 2], s[i - 1])) % MOD;
        }
        return dp[n];
    }
};