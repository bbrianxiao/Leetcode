class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int currMax = nums[0];
        int minSum = nums[0];
        int currMin = nums[0];
        for (int i = 1; i < n; i++) {
            currMax = max(currMax + nums[i], nums[i]);
            currMin = min(currMin + nums[i], nums[i]);
            maxSum = max(currMax, maxSum);
            minSum = min(currMin, minSum);
        }

        int total = accumulate(nums.begin(), nums.end(), 0);

        return total == minSum ? maxSum : max(maxSum, total - minSum);
        
    }
};