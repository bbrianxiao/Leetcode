# 273. Integer to English Words

## Overview
The `numberToWords` function in the `Solution` class converts a non-negative integer `num` to its English words representation. This solution breaks down the number into groups of three digits, converts each group into words, and then combines them with appropriate scale values (thousands, millions, etc.).

## Implementation Details
- **Predefined Word Lists**:
  - `ones`: Contains words for numbers 0 to 19.
  - `tens`: Contains words for multiples of ten from twenty to ninety.
  - `thousands`: Contains scale values such as "Thousand", "Million", and "Billion".

- **Conversion Logic**:
  - Handle the special case when `num` is `0`, immediately returning "Zero".
  - Use a loop to process each group of three digits:
    - Extract the last three digits using `num % 1000` and then divide `num` by `1000` to shift to the next group.
    - Convert each three-digit group from right to left, appending appropriate scale words from the `thousands` list.
    - If the group is non-zero:
      - Convert the hundreds place if it exists.
      - Convert the tens and ones places, checking if they fall within the teens or require separate handling for tens and ones.
    - Combine the converted group with the previously converted higher groups, ensuring words are added in correct sequence from the highest to the lowest place values.

- **String Manipulation**:
  - Accumulate results in `retval` string, adding group words in reverse order to handle groups from least significant to most significant.
  - Ensure spacing and formatting by trimming extra spaces at the end.

## Time and Space Complexities
- **Time Complexity**: `O(1)`, as the number of operations is constant relative to the size of the input. The loop iterates a maximum of four times (for numbers up to a billion).
- **Space Complexity**: `O(1)` for storing predefined word lists and temporary strings for result construction.

## Problem Link
For a detailed problem statement and constraints, visit [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/).

## Usage
```cpp
int num = 123456789;
Solution solution;
string result = solution.numberToWords(num);
// result will be "One Hundred Twenty Three Million Four Hundred Fifty Six Thousand Seven Hundred Eighty Nine"
