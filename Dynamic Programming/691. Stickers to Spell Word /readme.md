# 691. Stickers to Spell Word

## Overview
The `minStickers` function in the `Solution` class finds the minimum number of stickers required to spell a given target word. This problem is approached using dynamic programming combined with bit manipulation to represent subsets of the target string that have been covered by stickers.

## Implementation Details
- The function initializes a dynamic programming array `dp` where each index represents a subset of the target word, encoded as a bitmask. The value at each index is the minimum number of stickers required to achieve the corresponding subset.
- The initial state `dp[0]` is set to 0, indicating no stickers are needed to cover an empty subset.
- For each subset represented by `i`, if it's reachable (i.e., `dp[i] != INT_MAX`), the function iterates through each sticker.
- The `findNextState` helper function determines the new subset that can be formed by applying a sticker to the current subset. It does this by:
  - Iterating over each character in the sticker.
  - For each character, it looks for the first occurrence in the target that is not already covered in the current subset and marks it as covered.
- After determining the new subset `j` using a sticker, `dp[j]` is potentially updated to be the minimum of its current value or `dp[i] + 1` (indicating one more sticker used than for subset `i`).
- The function returns the value of `dp[n-1]` (where `n` is `1 << sz` and `sz` is the size of the target), which represents the minimum number of stickers needed to cover the entire target. If this value is `INT_MAX`, it returns `-1`, indicating that it's impossible to cover the target with the given stickers.

## Time and Space Complexities
- **Time Complexity**: `O(m * n * 2^n)`, where `m` is the number of stickers and `n` is the length of the target string. This complexity arises as for each of the `2^n` subsets, the function potentially processes each sticker (up to `n` characters long).
- **Space Complexity**: `O(2^n)`, as the dynamic programming table `dp` has `2^n` entries representing each possible subset of the target string.

## Problem Link
For a detailed problem statement and constraints, visit [Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/).

## Usage
```cpp
vector<string> stickers = {"with", "example", "science"};
string target = "thehat";

Solution solution;
int minStickersRequired = solution.minStickers(stickers, target);
// minStickersRequired will give the minimum number of stickers needed to form "thehat"
