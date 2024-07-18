class Solution {
public:
    int maximumSwap(int num) {
        string stringRepre = to_string(num);
        int n = stringRepre.size();
        vector<int> maxEleAfterCurr (n);
        int maxEle = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (stringRepre[i] > stringRepre[maxEle]) {
                maxEle = i;
            }
            maxEleAfterCurr[i] = maxEle;
        }

        for (int i = 0; i < n; i++) {
            int index = maxEleAfterCurr[i];
            if (stringRepre[index] > stringRepre[i]) {
                swap(stringRepre[index], stringRepre[i]);
                break;
            }
        }
        return stoi(stringRepre);
    }
};