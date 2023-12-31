class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string> Stack;
        string item;
        while (getline(ss, item, '/')) {
            if (item.empty() || item == ".") {
                continue;
            } else if (item == "..") {
                if (!Stack.empty()) {
                    Stack.pop();
                }
            } else {
                Stack.push(item);
            }
        }
        
        string retval;
        while (!Stack.empty()) {
            retval = "/" + Stack.top() + retval;
            Stack.pop();
        }

        return retval.empty() ? "/" : retval;

    }
};