class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> retval;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int sum = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == sum) {
                    retval.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (nums[left] + nums[right] < sum) {
                    left++;
                } else {
                    right--;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1]) {
                i++;
            }

        }
        return retval;
        
    }
};