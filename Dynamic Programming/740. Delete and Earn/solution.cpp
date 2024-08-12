class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp (100001, 0);
        for (int i : nums) {
            dp[i] += i;
        }

        int prev2 = 0, prev1 = dp[1];
        for (int i = 2; i < 100001; i++) {
            int temp = max(prev2 + dp[i], prev1);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;

    }
};