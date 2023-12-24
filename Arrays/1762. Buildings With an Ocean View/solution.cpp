class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        int currmin = -1;
        int n = heights.size();
        for (int i = n - 1; i >= 0; i--) {
            if (heights[i] > currmin) {
                currmin = heights[i];
                result.push_back(i);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
