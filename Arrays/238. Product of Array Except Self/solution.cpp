class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results (n, 1);
        int rproduct = nums[n - 1];
        for (int i = 1; i < nums.size(); i++) {
            results[i] = results[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            results[i] = results[i] * rproduct;
            rproduct *= nums[i];
        }
        return results;
    }
};