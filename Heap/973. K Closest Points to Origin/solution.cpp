class Solution {
public:
    double calculateDistance(const vector<int>& points) {
        return sqrt(points[0] * points[0] + points[1] * points[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(0, points.size() - 1, points, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    void quickSelect(int start, int end, vector<vector<int>>& points, int val) {
        double pivotDistance = calculateDistance(points[(start + end) / 2]);
        int i = start, j = start, k = end;
        while (j <= k) {
            double jDistance = calculateDistance(points[j]);
            if (jDistance > pivotDistance) {
                swap(points[j], points[k--]);
            } else if (jDistance < pivotDistance) {
                swap(points[i++], points[j++]);
            } else {
                j++;
            }
        }
        if (i - start >= val) {
            return quickSelect(start, i - 1, points, val);
        } else if (k - start + 1 >= val) {
            return;
        } else {
            return quickSelect(k + 1, end, points, val - (k - start + 1));
        }
    }
};