// Time Complexity : O(1) for all operations.
// Space Complexity : O(n).
// Idea: Maintain a stack of pairs that tracks the current min for each value

class MinStack {
    stack<pair<int, int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            int currMin = min(val, s.top().second);
            s.push({val, currMin});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */