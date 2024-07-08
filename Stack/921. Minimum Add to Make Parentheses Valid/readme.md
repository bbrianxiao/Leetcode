# 921. Minimum Add to Make Parentheses Valid

## Overview
The `minAddToMakeValid` function in the `Solution` class calculates the minimum number of parentheses that must be added to make a given string of parentheses valid. A string is valid if it is empty, or if it can be completely segmented into pairs of opening and closing parentheses.

## Implementation Details
- The function uses two counters, `opening` and `closing`, to keep track of unmatched opening `(` and closing `)` parentheses.
- As it iterates through the string, it increments the `opening` counter for each `(` found.
- For each `)`, if there are no unmatched opening parentheses (`opening` is 0), it increments the `closing` counter; otherwise, it decrements the `opening` counter.
- The function returns the sum of `opening` and `closing`, which represents the total number of unmatched parentheses needing a match.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the length of the input string. Each character in the string is processed exactly once.
- **Space Complexity**: `O(1)`, as the space used does not depend on the size of the input string but only on a few integer counters.

## Problem Link
For a detailed problem statement and constraints, visit [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/).

## Usage
```cpp
string s = "()))((";

Solution solution;
int minAdditions = solution.minAddToMakeValid(s);
// minAdditions will be 4
