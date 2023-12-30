# Basic Calculator - Two Versions

## Overview
This repository contains two versions of a `Solution` class, each implementing a basic calculator to evaluate a string containing non-negative integers and arithmetic operators ('+', '-', '*', '/'). Both versions handle arithmetic operations according to standard order of operations but differ in their approach to managing intermediate results.

## v1: Using Stack
### Implementation Details
- Utilizes a stack to handle arithmetic operations.
- Processes the expression as it is parsed, pushing intermediate results onto the stack.
- The final result is the sum of all values in the stack.

### Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the length of the string.
- **Space Complexity**: `O(N)`, for storing intermediate results in the stack.

## v2: Optimized Space Usage
### Implementation Details
- Maintains `lastNum` and `result` instead of using a stack.
- Updates `lastNum` and `result` on the fly during expression evaluation.
- The final result is the addition of `lastNum` to `result`.

### Time and Space Complexities
- **Time Complexity**: `O(N)`, similar to v1.
- **Space Complexity**: `O(1)`, more space-efficient than v1.

## Problem Link
For a detailed problem statement and constraints, visit [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/).

## Usage
```cpp
Solution solution;
string expression = "3+2*2";
int result = solution.calculate(expression);
// result will be 7
