class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int maxH = 0;
        for (int i = 0; i < citations.size(); i++) {
            cout << citations[i] << " " << i << endl;
            if (citations[i] >= i + 1) {
                maxH = i + 1;
            } else {
                return maxH;
            }
        }
        return maxH;
    }
};
