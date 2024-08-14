class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp (n + 1, 1);
        vector<int> prev (n + 1, -1);

        vector<int> retval;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    if (dp[j] == dp[i] + 1) {
                        prev[j] = i;
                    }
                }
            }
        }
        
        int maxLen = -1;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                idx = i;
            }
        }

        while (prev[idx] != -1) {
            retval.push_back(nums[idx]);
            idx = prev[idx];
        }
        retval.push_back(nums[idx]);
        return retval;
    }
};