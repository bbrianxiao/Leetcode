# 17. Letter Combinations of a Phone Number

## Overview
The `letterCombinations` function in the `Solution` class generates all possible letter combinations that the number could represent, given a string containing digits from 2-9. The mapping of digits to letters is the same as on the telephone buttons, e.g., '2' corresponds to "abc". The function employs a recursive backtracking approach to explore all potential combinations.

## Implementation Details
- **Mapping of Digits to Letters**:
  - An unordered map `letters` associates each digit with the corresponding string of letters it can represent, mimicking the layout of a traditional telephone keypad.

- **Recursive Helper Function (`helper`)**:
  - A recursive function designed to generate combinations by appending each possible letter corresponding to the current digit and then recursing to the next digit.
  - Parameters:
    - `digits`: The input string of digits.
    - `index`: The current position in the input string being processed.
    - `temp`: The current combination being built.
  - Base Case:
    - When the `index` reaches the length of `digits` and `temp` is not empty, add `temp` to `retval`.

- **Backtracking Mechanism**:
  - After a recursive call returns, the last character is removed (`temp.pop_back()`), which effectively backtracks to explore subsequent potential combinations using different characters for the current position.

## Time and Space Complexities
- **Time Complexity**: `O(N * 4^N)`, where `N` is the length of digits.
- **Space Complexity**: `O(N)`, where `N` is the length of the input `digits`. This space is used for the recursion call stack. Note that the space needed for the output is not included in the space complexity analysis.

## Problem Link
For a detailed problem statement and constraints, visit [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/).

## Usage
```cpp
Solution solution;
string digits = "23";
vector<string> result = solution.letterCombinations(digits);
// result will contain ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
