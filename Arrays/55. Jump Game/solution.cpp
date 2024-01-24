class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > far) return false;
            far = max(far, nums[i] + i);
        }
        return far >= nums.size() - 1;
    }
};