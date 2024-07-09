class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<pair<int, int>> dir {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int retval = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;
                    retval++;
                    while (!q.empty()) {
                        int currX = q.front().first;
                        int currY = q.front().second;
                        q.pop();
                        for (auto d : dir) {
                            int nextX = currX + d.first;
                            int nextY = currY + d.second;
                            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !vis[nextX][nextY] && grid[nextX][nextY] == '1') {
                                q.push({nextX, nextY});
                                vis[nextX][nextY] = true;
                            }
                        }
                    }
                }
            }
        }
        return retval;
    }
};