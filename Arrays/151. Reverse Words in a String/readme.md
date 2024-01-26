# 151. Reverse Words in a String

## Overview
The `reverseWords` function reverses the words in a given string `s`. Each word in the string is separated by one or more spaces, and the reversed string should contain words separated by a single space without leading or trailing spaces.

## Implementation Details
- The function uses a `stringstream` to parse the words in the string `s`.
- It reads the first word and initializes the `result` string with it.
- For each subsequent word, it concatenates it to the front of the `result` string, ensuring that words are reversed.
- Spaces are added between words during concatenation.
- The final `result` string contains all the words from the original string in reverse order.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the length of the string `s`. The function iterates over each character of the string.
- **Space Complexity**: `O(N)`, as additional space is used to store the words and the final reversed string.

## Problem Link
For a detailed problem statement and constraints, visit [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/description/).

## Usage
```cpp
Solution solution;
string s = "the sky is blue";
string result = solution.reverseWords(s);
// result will be "blue is sky the"
