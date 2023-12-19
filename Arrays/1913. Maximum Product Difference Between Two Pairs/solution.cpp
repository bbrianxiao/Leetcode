// Time Complexity : O(n) We iterate over nums once, performing O(1) work at each iteration.
// Space Complexity : O(1)
// Idea: Track the Two Biggest and the Two Smallest Elements

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int biggest = 0;
        int secondBiggest = 0;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = max(secondBiggest, num);
            }

            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = min(secondSmallest, num);
            }
        }

        return biggest * secondBiggest - smallest * secondSmallest;
    }
};
