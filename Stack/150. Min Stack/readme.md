# 150. MinStack

## Implementation Details
- Utilizes a stack of pairs where each pair comprises the element and the current minimum.
- Every `push` operation recalculates the current minimum and associates it with the element.
- The `getMin` operation simply fetches the current minimum from the stack's top.

## Time and Space Complexities
- **Time Complexity**: All operations (`push`, `pop`, `top`, and `getMin`) are executed in constant time, `O(1)`.
- **Space Complexity**: The space used by MinStack is linear, `O(n)`, where `n` is the number of items in the stack.

## Usage
```cpp
MinStack* obj = new MinStack();
obj->push(val);
obj->pop();
int top_val = obj->top();
int min_val = obj->getMin();