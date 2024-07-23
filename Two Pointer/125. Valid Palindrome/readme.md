# 125. Valid Palindrome

## Overview
The `isPalindrome` function in the `Solution` class checks whether a given string `s` is a palindrome, considering only alphanumeric characters and ignoring cases. A palindrome is a string that reads the same backward as forward.

## Implementation Details
- **Two-Pointer Approach**:
  - Initialize two pointers, `left` at the beginning of the string and `right` at the end.
  - Traverse the string from both ends towards the center:
    - Increment the `left` pointer until it points to an alphanumeric character.
    - Decrement the `right` pointer until it points to an alphanumeric character.
    - Compare the characters at these two positions after converting them to lowercase:
      - If they match, move both pointers inward to continue checking.
      - If they do not match, return `false` immediately.
- **Completion Check**:
  - If the pointers meet in the middle without finding any mismatched characters, return `true`, indicating the string is a palindrome.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the length of the string `s`. In the worst case, each character is visited twice (once by each pointer).
- **Space Complexity**: `O(1)`, as the solution uses a constant amount of extra space for the two pointers and a few other variables, irrespective of the input size.

## Problem Link
For a detailed problem statement and constraints, visit [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/).

## Usage
```cpp
string s = "A man, a plan, a canal: Panama";
Solution solution;
bool result = solution.isPalindrome(s);
// result will be true because the string, when filtered for alphanumerics and ignoring cases, reads the same forward and backward.
