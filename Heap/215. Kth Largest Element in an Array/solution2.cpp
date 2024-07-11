class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(0, nums.size() - 1, nums, k);
    }

    int quickSelect(int start, int end, vector<int>& nums, int k) {
        int pivot = nums[(start + end) / 2];
        int x = start, y = start, z = end;
        while (y <= z) {
            if (nums[y] > pivot) {
                swap(nums[y], nums[z--]);
            } else if (nums[y] < pivot) {
                swap(nums[y++], nums[x++]);
            } else {
                y++;
            }
        }
        if (end - z >= k) {
            return quickSelect(z + 1, end, nums, k);
        } else if (end - x + 1 >= k) {
            return pivot;
        } else {
            return quickSelect(start, x - 1, nums, k - (end - x + 1));
        }
    }
};