class Solution {
public:
    string simplifyPath(string path) {
        stack<string> Stack;
        stringstream ss(path);
        string item;
        while (getline(ss, item, '/')) {
            if (item == "..") {
                if (!Stack.empty()) {
                    Stack.pop();
                }
            } else if (!item.empty() && item != ".") {
                Stack.push(item);
            }
        }

        string retval;
        while (!Stack.empty()) {
            retval = "/" + Stack.top() + retval;
            Stack.pop();
        }
        return retval == "" ? "/" : retval;
    }
};