# 2125. Number of Laser Beams in a Bank

## Overview
The `numberOfBeams` function calculates the total number of laser beams formed in a bank's security system. The bank's security system is represented as a grid, where each row of the grid is given as a string in the `bank` vector. Each '1' in the string represents a security device that can form laser beams to other devices in different rows.

## Implementation Details
- The function iterates over each row (string) in the `bank` vector.
- For each row, it counts the number of security devices ('1's).
- The number of beams formed by devices in the current row is the product of the number of devices in the current row and the number in the previous row with devices.
- The total number of beams (`ans`) is the sum of beams formed by each row.
- Rows without devices ('0's only) do not contribute to the beam count and are skipped.

## Time and Space Complexities
- **Time Complexity**: `O(N*M)`, where `N` is the number of rows, and `M` is the length of each row in the `bank` vector. Each character in the grid is processed once.
- **Space Complexity**: `O(1)`, as the solution uses a constant amount of additional space.

## Problem Link
For a detailed problem statement and constraints, visit [Number of Laser Beams in a Bank](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03).

## Usage
```cpp
Solution solution;
vector<string> bank = {"011", "100", "000", "001"};
int result = solution.numberOfBeams(bank);
// result will be the total number of laser beams formed in the bank's security system
