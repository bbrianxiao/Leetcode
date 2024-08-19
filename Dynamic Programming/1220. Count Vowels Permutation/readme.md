# 1220. Count Vowels Permutation

## Overview
The `countVowelPermutation` function in the `Solution` class computes the number of strings of length `n` consisting only of vowels that satisfy certain rules on the order of vowels. The function uses a dynamic programming approach to count the valid sequences, adhering to specific transitions between vowels based on their positions.

## Implementation Details
- **Dynamic Programming Setup**:
  - A 2D vector `dp` is used, with `dp[i][j]` representing the number of valid sequences of length `i` ending with the vowel represented by index `j` (`0: 'a'`, `1: 'e'`, `2: 'i'`, `3: 'o'`, `4: 'u'`).
  - The first row (`dp[1]`) is initialized with `1` for each vowel, representing the single-letter strings.

- **Transition Rules**:
  - The transitions between vowels from one position to the next are predefined:
    - `a` follows from `e`, `i`, or `u`.
    - `e` follows from `a` or `i`.
    - `i` follows from `e` or `o`.
    - `o` follows only from `i`.
    - `u` follows from `i` or `o`.
  - These rules are translated into updates for the `dp` table for each sequence length up to `n`.

- **Iterative Calculation**:
  - For each length from `2` to `n`, update the counts in `dp[i]` based on the counts from `dp[i-1]` using the specified rules, ensuring that counts are taken modulo `MOD` to prevent overflow and adhere to problem constraints.

- **Result Accumulation**:
  - Sum the counts of all sequences of length `n` from `dp[n]` to get the total number of valid sequences.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the given length of the sequences. The method processes each length from `1` to `n` once, updating five states for each step.
- **Space Complexity**: `O(n)`, due to the storage of the `dp` table with `n+1` rows and `5` columns representing the counts for each vowel at each step up to `n`.

## Problem Link
For a detailed problem statement and constraints, visit [Count Vowels Permutation](https://leetcode.com/problems/count-vowels-permutation/).

## Usage
```cpp
int n = 5;
Solution solution;
int result = solution.countVowelPermutation(n);
// result will be the number of valid strings of length 5 following the vowel permutation rules.
