class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = -1;
        int preSum = 0;
        int retval = 0;
        for (int i = 0; i < n; i++) {
            preSum += (nums[i] == 1) ? 1 : -1;
            if (m.find(preSum) != m.end()) {
                retval = max(retval, i - m[preSum]);
            } else {
                m[preSum] = i;
            }
        }
        return retval;

    }
};