class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> retval;
        int n = encoded1.size();
        int m = encoded2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {

            int prod = encoded1[i][0] * encoded2[j][0];
            int freq = min(encoded1[i][1], encoded2[j][1]);

            if (!retval.empty() && prod == retval.back()[0]) {
                retval.back()[1] += freq;
            } else {
                retval.push_back({prod, freq});
            }

            if (encoded1[i][1] < encoded2[j][1]) {
                i++;
                encoded2[j][1] -= freq;
            } else if (encoded1[i][1] > encoded2[j][1]) {
                j++;
                encoded1[i][1] -= freq;
            } else {
                i++;
                j++;
            }
        }
        return retval;
    }
};