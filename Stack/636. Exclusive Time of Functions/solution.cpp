class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> retval (n, 0);
        stack<int> Stack;
        int prevTime = 0;
        for (auto str : logs) {
            int j = 0;
            while (str[j] != ':') j++;
            int funcId = stoi(str.substr(0, j));
            bool isStart = str[++j] == 's';
            while (str[j] != ':') j++;
            int time = stoi(str.substr(j + 1, str.size() - j));
            if (isStart) {
                if (!Stack.empty()) {
                    retval[Stack.top()] += time - prevTime;
                }
                prevTime = time;
                Stack.push(funcId);
            } else {
                retval[Stack.top()] += time + 1 - prevTime;
                Stack.pop();
                prevTime = time + 1;
            }

        }
        return retval;
    }
};