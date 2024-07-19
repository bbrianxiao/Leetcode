class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> retval;
        int n = mat.size();
        int m = mat[0].size();
        int row = 0, col = 0;
        bool direction = true;
        for (int i = 0; i < n * m; i++) {
            retval.push_back(mat[row][col]);
            if (direction) {
                 if (col == m - 1) {
                    row++;
                    direction = !direction;
                } else if (row == 0) {
                    col++;
                    direction = !direction;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == n - 1) {
                    col++;
                    direction = !direction;
                } else if (col == 0) {
                    row++;
                    direction = !direction;
                } else {
                    row++;
                    col--;
                }
            }
        }
        return retval;
    }
};