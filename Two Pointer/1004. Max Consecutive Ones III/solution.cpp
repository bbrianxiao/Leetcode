class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int retval = 0;
        int currMax = 0;
        int kleft = k;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            currMax++;
            if (nums[j] == 0) kleft--;
            while (kleft < 0) {
                if (nums[i] == 0) {
                    kleft++;
                }
                currMax--;
                i++;
            }
            retval = max(retval, currMax);
        }
        return retval;
    }
};class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int retval = 0;
        int currMax = 0;
        int kleft = k;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            currMax++;
            if (nums[j] == 0) kleft--;
            while (kleft < 0) {
                if (nums[i] == 0) {
                    kleft++;
                }
                currMax--;
                i++;
            }
            retval = max(retval, currMax);
        }
        return retval;
    }
};