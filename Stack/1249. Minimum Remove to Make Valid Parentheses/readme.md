# 1249. Minimum Removal to Make Valid Parentheses

## Implementation Details
The implementation utilizes a stack to keep track of unmatched parentheses. The algorithm includes:

1. Iterating over each character in the string.
2. Pushing the index of each opening parenthesis `(` onto the stack.
3. For each closing parenthesis `)`, if the stack is empty, mark it for removal; otherwise, pop from the stack.
4. After iterating, any remaining indices in the stack (unmatched opening parentheses) are marked for removal.
5. Constructing the final string by excluding the marked indices.

## Time and Space Complexity
- **Time Complexity**: `O(n)`, where `n` is the length of the string.
- **Space Complexity**: `O(n)` in the worst case, with all characters being opening parentheses.
