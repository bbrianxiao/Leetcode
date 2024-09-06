class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> retval;
        for (int i = 0; i < intervals.size(); ) {
            int j = i;
            int start = intervals[j][0];
            int end = intervals[j][1];
            while (j < intervals.size() && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                start = min(start, intervals[j][0]);
                j++;
            }
            retval.push_back({start, end});
            i = j;
        }
        return retval;
    }
};