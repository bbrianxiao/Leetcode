class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        double maxSoFar = nums[0], minSoFar = nums[0];
        double retval = maxSoFar;
        for (int i = 1; i < n; i++) {
            double temp = max(maxSoFar * nums[i], max(minSoFar * nums[i], (double)nums[i]));
            minSoFar = min(maxSoFar * nums[i], min(minSoFar * nums[i], (double)nums[i]));
            maxSoFar = temp;
            cout << maxSoFar << " " << minSoFar << endl;
            retval = max(maxSoFar, retval);
        }
        return (int)retval;
        
    }
};