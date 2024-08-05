class Solution {
public:
	long long sellingWood(int m, int n, vector<vector<int>>& prices) {     
		vector<vector<long long>> dp(m+1,vector<long long>(n+1,0)); 

		for(int i = 0;i < prices.size();i++)
			dp[prices[i][0]][prices[i][1]] = prices[i][2];

		for(int row = 1;row <= m;row++){
			for(int col = 1;col <= n;col++){

				long long ans = dp[row][col]; 

				for(int i = 1;i <= row/2;i++) 
					ans = max(ans,dp[i][col] + dp[row-i][col]);

				for(int j = 1;j <= col/2;j++)
					ans = max(ans,dp[row][j] + dp[row][col-j]);

				dp[row][col] = ans;
			}
		}

		return dp[m][n];
	}
};