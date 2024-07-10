# 636. Exclusive Time of Functions

## Overview
The `exclusiveTime` function in the `Solution` class calculates the exclusive time spent on each function in a single-threaded CPU program, based on logs detailing when each function starts and ends. Exclusive time refers to the time spent in a function excluding the time spent in any functions called by it.

## Implementation Details
- The function initializes a result vector, `retval`, to store the exclusive time for each function and a stack to manage function calls.
- It iterates through each log entry, parsing the function ID and the timestamp, and determines whether it's a start or end log.
- If the log is a "start":
  - If the stack is not empty, it adds the time elapsed since the last timestamp to the function currently at the top of the stack.
  - It then updates `prevTime` and pushes the current function ID onto the stack.
- If the log is an "end":
  - It calculates the time spent since `prevTime`, ensuring to include the current timestamp, and adds it to the function that is ending.
  - The function ID is then popped from the stack, and `prevTime` is updated to the time after the current timestamp to account for the next start or end.
- The stack is used to track which function is currently executing and helps calculate the nested execution times.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of log entries. Each log entry is processed once.
- **Space Complexity**: `O(N)`, where `N` is the number of functions. The stack may contain up to `N` entries if all functions are called nestedly before any of them returns.

## Problem Link
For a detailed problem statement and constraints, visit [Exclusive Time of Functions](https://leetcode.com/problems/exclusive-time-of-functions/).

## Usage
```cpp
vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
int n = 2;

Solution solution;
vector<int> result = solution.exclusiveTime(n, logs);
// result will be [3, 4] indicating the exclusive time for function 0 and function 1 respectively
