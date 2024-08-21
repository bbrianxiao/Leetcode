class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            prefixSum %= k;
            if (m.find(prefixSum) != m.end()) {
                if (i - m[prefixSum] >= 2) {
                    return true;
                }
            } else {
                m[prefixSum] = i;
            }
        }
        return false;
    }
};
