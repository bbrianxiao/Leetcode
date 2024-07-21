class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> retval (k, vector<int>(k, 0));
        vector<unordered_set<int>> adjList (k);
        vector<int> Rowcounts (k, 0);
        vector<int> Colcounts (k, 0);
        unordered_map<int, int> rowMap;
        unordered_map<int, int> colMap;
        for (auto row : rowConditions) {
            if (adjList[row[1] - 1].find(row[0] - 1) != adjList[row[1] - 1].end()) continue;
            Rowcounts[row[0] - 1]++;
            adjList[row[1] - 1].insert(row[0] - 1);
        }
        queue<int> q;
        // 1 2 3 4 5 6
        // 1: 4, 2
        // 4: 3

        for (int i = 0; i < k; i++) {
            if (Rowcounts[i] == 0) {
                q.push(i + 1);
            }
        }
        int counter = k - 1;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            rowMap[top] = counter--;
            for (auto i : adjList[top - 1]) {
                Rowcounts[i]--;
                if (Rowcounts[i] == 0) q.push(i + 1);
            }
        }

        if (rowMap.size() != k) return {};

        adjList.clear();
        adjList.resize(k);
        for (auto col : colConditions) {
            if (adjList[col[1] - 1].find(col[0] - 1) != adjList[col[1] - 1].end()) continue;
            Colcounts[col[0] - 1]++;
            adjList[col[1] - 1].insert(col[0] - 1);
        }

        for (int i = 0; i < k; i++) {
            if (Colcounts[i] == 0) {
                q.push(i + 1);
            }
        }

        counter = k - 1;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            colMap[top] = counter--;
            for (auto i : adjList[top - 1]) {
                Colcounts[i]--;
                if (Colcounts[i] == 0) q.push(i + 1);
            }
        }

        if (colMap.size() != k) return {};

        for (int i = 1; i <= k; i++) {
            retval[rowMap[i]][colMap[i]] = i; 
        }

        return retval;
    }
};