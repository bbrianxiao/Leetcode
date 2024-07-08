class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int retval = INT_MAX;
        vector<vector<bool>> vis (n, vector<bool> (n, false));
        queue<tuple<int, int, int>> q;
        vector<pair<int, int>> dir {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
        if (grid[0][0] != 0) return -1;
        q.push({0, 0, 1});
        while (!q.empty()) {
            int currX = get<0>(q.front());
            int currY = get<1>(q.front());
            int currDis = get<2>(q.front());
            q.pop();
            if (currX == n - 1 && currY == n - 1) {
                retval = min(retval, currDis);
            }
            for (auto d : dir) {
                int nextX = currX + d.first;
                int nextY = currY + d.second;
                if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && !vis[nextX][nextY] && grid[nextX][nextY] == 0) {
                    q.push({nextX, nextY, currDis + 1});
                    vis[nextX][nextY] = true;
                }
            }
        }

        return retval == INT_MAX ? -1 : retval;
    }
};