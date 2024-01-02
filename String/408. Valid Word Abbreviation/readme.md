# 408. Valid Word Abbreviation

## Implementation Details
- The function `validWordAbbreviation` checks if a given abbreviation is a valid abbreviation of a given word.
- It iterates through the abbreviation string. If a digit is encountered, it calculates the number it represents (which indicates the number of characters to skip in the word).
- If a non-digit character is encountered, it checks if the character matches the corresponding character in the word.
- The function returns `false` immediately if any mismatch is found or if the abbreviation tries to skip more characters than are present in the word.

## Time and Space Complexities
- **Time Complexity**: The time complexity is `O(n)` where `n` is the length of the abbreviation string. The function makes a single pass through the abbreviation string.
- **Space Complexity**: The space complexity is `O(1)` as the function uses a constant amount of space regardless of the input size.

## Problem Link
For a detailed problem statement and constraints, visit [Valid Word Abbreviation](https://leetcode.com/problems/valid-word-abbreviation/description/).
