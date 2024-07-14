class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> m;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int counter = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = counter;
                    int area = 0;
                    while (!q.empty()) {
                        int currX = q.front().first;
                        int currY = q.front().second;
                        q.pop();
                        area++;
                        for (auto d : dir) {
                            int nextX = currX + d.first;
                            int nextY = currY + d.second;
                            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && grid[nextX][nextY] == 1) {
                                q.push({nextX, nextY});
                                grid[nextX][nextY] = counter;
                            }
                        }
                    }
                    m[counter++] = area;
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> s;
                    int Area = 0;
                    for (auto d : dir) {
                        int nextX = i + d.first;
                        int nextY = j + d.second;
                        if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n) {
                            int counter = grid[nextX][nextY];
                            if (s.find(counter) == s.end()) {
                                Area += m[counter];
                                s.insert(counter);
                            }
                        }
                    }
                    maxArea = max(maxArea, Area);
                }
            }
        }

        cout << m[2];

        if (maxArea == 0 && grid[0][0] != 0) {
            return n * n;
        }
        return maxArea + 1;
    }
};