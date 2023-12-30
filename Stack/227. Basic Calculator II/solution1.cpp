class Solution {
public:
    int calculate(string s) {
        stack<int> Stack;
        int currNum = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            char currChar = s[i];
            if (isdigit(currChar)) {
                currNum = currNum * 10 + (currChar - '0');
            }
            if (!isdigit(currChar) && !iswspace(currChar) || i == s.size() - 1) {
                if (sign == '+') {
                    Stack.push(currNum);
                } else if (sign == '-') {
                    Stack.push(-currNum);
                } else if (sign == '*') {
                    int stackTop = Stack.top();
                    Stack.pop();
                    Stack.push(stackTop * currNum);
                } else if (sign == '/') {
                    int stackTop = Stack.top();
                    Stack.pop();
                    Stack.push(stackTop / currNum);
                }
                sign = currChar;
                currNum = 0;
            }
        }
        int result = 0;
        while (!Stack.empty()) {
            result += Stack.top();
            Stack.pop();
        }
        return result;
    }
};