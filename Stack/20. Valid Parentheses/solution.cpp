class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for (auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                Stack.push(c);
            } else {
                if (Stack.empty()) return false;
                if (c == ')') {
                    if (Stack.top() != '(') return false;
                } else if (c == '}') {
                    if (Stack.top() != '{') return false;
                } else {
                    if (Stack.top() != '[') return false;
                }
                Stack.pop();
            }
        }
        return Stack.empty();
    }
};