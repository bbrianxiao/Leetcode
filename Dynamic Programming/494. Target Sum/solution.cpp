class Solution {
    unordered_map<string, int> m;
public:
    int dfs(vector<int>& nums, int i, int currSum, int target) {
        if (i == nums.size()) {
            return currSum == target ? 1 : 0;
        }
        string key = to_string(i) + "," + to_string(currSum);
        if (m.find(key) != m.end()) {
            return m[key];
        } else {
            m[key] = dfs(nums, i + 1, currSum + nums[i], target) + dfs(nums, i + 1, currSum - nums[i], target);
            return m[key];
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, 0, 0, target);
    }
};