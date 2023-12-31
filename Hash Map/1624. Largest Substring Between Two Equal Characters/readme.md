# 1624. Max Length Between Equal Characters

## Overview
The `maxLengthBetweenEqualCharacters` function in the `Solution` class finds the maximum length of a substring located between two identical characters in a given string. If no such substring exists, it returns -1.

## Implementation Details
- The function initializes a vector `v` of size 26 (representing the lowercase English alphabet) with `-1` to track the first occurrence of each character.
- It iterates over the string `s`, updating `v` with the index of the first occurrence of each character.
- When it encounters a character that has appeared before, it calculates the length of the substring between the two occurrences of that character and updates `maxlen` if this length is greater than the current `maxlen`.
- The function returns the maximum length found.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the length of the input string `s`. The function iterates through each character of the string once.
- **Space Complexity**: `O(1)`, as the space used by the vector `v` is constant, irrespective of the input size.

## Problem Link
For a detailed problem statement and constraints, visit [Largest Substring Between Two Equal Characters](https://leetcode.com/problems/largest-substring-between-two-equal-characters/?envType=daily-question&envId=2023-12-31).

## Usage
```cpp
Solution solution;
string s = "abca";
int result = solution.maxLengthBetweenEqualCharacters(s);
// result will be 2, as the maximum length between two identical characters ('a') is 2
