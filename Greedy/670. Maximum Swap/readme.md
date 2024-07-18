# 670. Maximum Swap

## Overview
The `maximumSwap` function in the `Solution` class determines the maximum number you can get by swapping two digits at most once in a given integer `num`. This method strategically selects digits to swap in order to maximize the number.

## Implementation Details
- **String Conversion**:
  - Convert the integer `num` to its string representation to facilitate easy swapping of digits.
- **Tracking Maximum Digits**:
  - Use a vector `maxEleAfterCurr` to track the index of the maximum digit found from each position to the end of the number.
  - Traverse the string representation from right to left to fill this vector. If the current digit is greater than the known maximum, update the maximum index.
- **Determine Swap**:
  - Traverse the string representation from left to right to find the first digit that is not the maximum digit following it (as per `maxEleAfterCurr`).
  - Perform a swap between this digit and the maximum digit that follows it if the maximum digit is greater.
  - Break after the first successful swap since only one swap is allowed.
- **Conversion and Return**:
  - Convert the modified string back to an integer and return this value.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of digits in `num`. The function requires a single pass to build the `maxEleAfterCurr` and another to potentially swap digits.
- **Space Complexity**: `O(N)` for storing the `maxEleAfterCurr` vector and the temporary string representation of the number.

## Problem Link
For a detailed problem statement and constraints, visit [Maximum Swap](https://leetcode.com/problems/maximum-swap/).

## Usage
```cpp
int num = 2736;
Solution solution;
int result = solution.maximumSwap(num);
// result will be 7236, obtained by swapping the 2 and 7
