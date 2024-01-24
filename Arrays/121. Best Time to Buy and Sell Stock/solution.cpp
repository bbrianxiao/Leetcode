class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX - 1;
        int maxDiff = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < mini) {
                mini = prices[i];
            }
            maxDiff = max(maxDiff, prices[i] - mini);
            
        }
        return maxDiff;
    }
};