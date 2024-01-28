class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> course (n, 0);
        vector<vector<int>> adjList(n, vector<int> ());
        for (auto p : relations) {
            int prevCourse = p[0];
            int nextCourse = p[1];
            prevCourse--;
            nextCourse--;
            course[nextCourse]++;
            adjList[prevCourse].push_back(nextCourse);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (course[i] == 0) {
                q.push(i);
            }
        }

        int numSemester = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                for (auto c : adjList[curr]) {
                    course[c]--;
                    if (course[c] == 0) {
                        q.push(c);
                    }
                }
            }
            numSemester++;
        }

        for (auto i : course) {
            if (i > 0) {
                return -1;
            }
        }
        return numSemester;
    }
};