# 1444. Number of Ways of Cutting a Pizza

## Overview
The `ways` function in the `Solution` class calculates the number of ways to cut a pizza into `k` pieces, each containing at least one apple. This function uses dynamic programming (DP) combined with prefix sums to efficiently determine the number of valid partitions.

## Implementation Details
- **Prefix Sum Array**:
  - A 2D prefix sum array `prefix` is used to quickly calculate the number of apples in any subrectangle of the pizza. `prefix[i][j]` represents the number of apples from the top-left corner to the cell `(i, j)`.
  - The prefix sum is computed such that `prefix[i][j] = (pizza[i][j] == 'A') + prefix[i + 1][j] + prefix[i][j + 1] - prefix[i + 1][j + 1]`.

- **Dynamic Programming Table**:
  - A 3D DP table `dp[cut][i][j]` stores the number of ways to cut the sub-pizza starting at `(i, j)` into `cut + 1` pieces.
  - Initialization for `k = 1` (base case): If there is at least one apple in the sub-pizza starting at `(i, j)`, then `dp[0][i][j] = 1`.

- **Transition Between States**:
  - For each possible starting point `(i, j)` and each cut from `1` to `k-1`, compute the number of valid ways to cut by trying all possible horizontal and vertical cuts:
    - **Horizontal cuts**: Check if placing a horizontal cut between rows `i` and `x` leaves at least one apple on the top part; if so, add the ways from the bottom part to the current state.
    - **Vertical cuts**: Similarly, check vertical cuts between columns `j` and `y`.

- **Modular Arithmetic**:
  - Since the result could be very large, all operations are performed modulo `1e9 + 7` (`MOD`) to keep numbers manageable and prevent overflow.

## Time and Space Complexities
- **Time Complexity**: `O(m * n * k * (m + n))`, where `m` and `n` are the dimensions of the pizza, and `k` is the number of pieces. The complexity comes from computing ways for each sub-pizza for each cut, considering every possible horizontal and vertical cut.
- **Space Complexity**: `O(m * n * k)` due to the DP table that stores the results for every sub-pizza and number of cuts, as well as the prefix sum array.

## Problem Link
For a detailed problem statement and constraints, visit [Number of Ways of Cutting a Pizza](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/).

## Usage
```cpp
vector<string> pizza = {"AAAA", "AABA", "AAAA", "AAAA"};
int k = 4;
Solution solution;
int result = solution.ways(pizza, k);
// result will be the number of ways to cut the pizza into k pieces such that each piece has at least one apple.
