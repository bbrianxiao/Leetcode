class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int seq_length = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                dp[i][diff] = max(dp[i][diff], seq_length);
                max_len = max(max_len, dp[i][diff]);
            }
        }

        return max_len;
    }
};
