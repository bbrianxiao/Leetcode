class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            if (dp.empty()) {
                dp.push_back(nums[i]);
            } else {
                if (nums[i] <= dp.back()) {
                    auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                    *it = nums[i];
                } else {
                    dp.push_back(nums[i]);
                }
            }
        }
        return dp.size();
    }
};