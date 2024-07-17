# 65. Valid Number

## Overview
The `isNumber` function in the `Solution` class determines if a given string can be interpreted as a decimal number. This includes integers, floating numbers, and numbers with an exponent part (scientific notation). The function handles leading/trailing white spaces and signs.

## Implementation Details
- **Whitespace Handling**:
  - The function begins by skipping any leading whitespace characters to find the start of the number.
- **Sign Handling**:
  - Directly after the leading whitespaces, a single optional `+` or `-` sign is allowed.
- **Main Parsing Loop**:
  - The function then checks each character to validate the structure of the number:
    - **Digits**: A section of contiguous digits sets `isNumeric` to `true`.
    - **Decimal Point**: Only one decimal point is allowed, and it cannot appear after an exponent.
    - **Exponent**: The letter 'e' or 'E' indicates the start of an exponent, which must follow a valid number and can only appear once. After the exponent, the number must contain another valid integer (which can also have a sign).
- **Trailing Characters**:
  - After parsing the main body of the number, any remaining characters must be whitespace for the string to be considered a valid number.
- **Final Checks**:
  - The string is considered a valid number if there were digits in both the base and the exponent part (if an exponent exists) and if the parsing has reached the end of the string after skipping any trailing whitespace.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the length of the string. The function traverses the string up to two times (once for the main parsing and once for trailing whitespace).
- **Space Complexity**: `O(1)`, as the solution uses only a few variables for state tracking, regardless of the input size.

## Problem Link
For a detailed problem statement and constraints, visit [Valid Number](https://leetcode.com/problems/valid-number/).

## Usage
```cpp
string s = " -90e3   ";
Solution solution;
bool result = solution.isNumber(s);
// result will be true because "-90e3" is a valid representation of a scientific number.
