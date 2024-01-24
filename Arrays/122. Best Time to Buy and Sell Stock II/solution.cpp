class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMax = prices[0];
        int maxProfit = 0;
        int currMin = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < currMax) {
                maxProfit += currMax - currMin;
                currMin = prices[i];
            }
            currMax = prices[i];
        }
        return maxProfit + (currMax - currMin);
    }
};