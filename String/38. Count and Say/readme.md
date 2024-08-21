# 38. Count and Say

## Overview
The `countAndSay` function in the `Solution` class generates the `n`-th term of the count-and-say sequence. This sequence starts with "1", and each subsequent term is constructed by describing the count of consecutive digits in the previous term.

## Implementation Details
- **Base Case**:
  - For `n = 1`, the sequence directly returns "1".

- **Sequence Generation**:
  - Begin with the initial string "1" for `n = 1`.
  - For each subsequent value of `n` up to the target `n`:
    - Initialize an empty string `current` to build the next term.
    - Use variables `count` to track the number of similar consecutive digits and `say` to note the digit being counted.
    - Traverse the current result string, updating `count` and `say` as changes in consecutive digits are detected.
    - Append the count and digit to `current` whenever a new digit is encountered or the string traversal completes.
    - Update `result` with the newly formed `current` string for the next iteration.

## Time and Space Complexities
- **Time Complexity**: O(m * n), where `m` is the average length of the result string for each term and `n` is the given term number. Each term is processed based on the length of the term before it, which potentially grows each time.
- **Space Complexity**: O(m), where `m` is the maximum length of the sequence generated up to the `n`-th term. This is because each new term is stored as a separate string.

## Problem Link
For a detailed problem statement and constraints, visit [Count and Say](https://leetcode.com/problems/count-and-say/).

## Usage
```cpp
Solution solution;
int n = 5;
string result = solution.countAndSay(n);
// result will be "111221", as the sequence progresses: 1, 11, 21, 1211, 111221.
