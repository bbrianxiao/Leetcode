class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currgas = 0;
        int totalgas = 0;
        int maxStart = 0;
        for (int i = 0; i < gas.size(); i++) {
            currgas += gas[i] - cost[i];
            if (currgas < 0) {
                maxStart = i + 1;
                totalgas += currgas;
                currgas = 0;
            }
        }
        totalgas += currgas;

        if (totalgas < 0) return -1;
        return maxStart;
    }
};