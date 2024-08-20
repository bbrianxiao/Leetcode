class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> swaps (n + 1, 0);
        vector<int> noSwaps (n + 1, 0);
        swaps[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
                if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                    swaps[i] = min(swaps[i - 1], noSwaps[i - 1]) + 1;
                    noSwaps[i] = min(noSwaps[i - 1], swaps[i - 1]);
                } else {
                    swaps[i] = swaps[i - 1] + 1;
                    noSwaps[i] = noSwaps[i - 1];
                }
            } else {
                swaps[i] = noSwaps[i - 1] + 1;
                noSwaps[i] = swaps[i - 1];
            }
        }
        return min(swaps[n - 1], noSwaps[n - 1]);
    }
};