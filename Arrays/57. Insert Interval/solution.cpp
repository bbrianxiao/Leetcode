class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0]) {
            ret.push_back(intervals[i]);
            i++;
        }

        int start = newInterval[0];
        int end = newInterval[1];
        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        ret.push_back({start, end});

        while (i < n) {
            ret.push_back(intervals[i]);
            i++;
        }

        return ret;
    }
};
