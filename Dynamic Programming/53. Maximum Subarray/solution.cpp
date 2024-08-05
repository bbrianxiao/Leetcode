class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, nums[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }

        int retval = dp[0];
        for (int i = 0; i < n; i++) {
            retval = max(retval, dp[i]);
        }
        return retval;
    }
};