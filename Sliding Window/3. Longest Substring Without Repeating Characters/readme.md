# 3. Longest Substring Without Repeating Characters

## Overview
The `lengthOfLongestSubstring` function determines the length of the longest substring without repeating characters in a given string `s`. 

## Implementation Details
- The function uses a sliding window approach with two pointers `i` and `j` to traverse the string.
- An unordered map `m` is used to keep track of the characters in the current window and their frequencies.
- The window is extended by moving `j` forward and each character encountered is added to the map.
- If a duplicate character is found (when `m[c] > 1`), the left end of the window (`i`) is moved forward until the duplicate is removed.
- The maximum length of a valid window (substring with no repeating characters) is tracked by `maxLen`.
- The function iterates through the string once, updating the maximum length of the substring as it goes.

## Time and Space Complexities
- **Time Complexity**: `O(2N) = O(N)`, where `N` is the length of the string `s`. The function uses a sliding window, which passes over each character of the string once (worst case twice).
- **Space Complexity**: `O(min(N, M))`, where `M` is the size of the character set. The unordered map stores each character that appears in the substring.

## Problem Link
For a detailed problem statement and constraints, visit [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/).

## Usage
```cpp
Solution solution;
string s = "abcabcbb";
int result = solution.lengthOfLongestSubstring(s);
// result will be 3, as the longest substring without repeating characters is "abc".
