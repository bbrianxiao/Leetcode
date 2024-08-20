# 801. Minimum Swaps to Make Sequences Increasing

## Overview
The `minSwap` function in the `Solution` class calculates the minimum number of swaps required to make two sequences (`nums1` and `nums2`) strictly increasing. The function employs a dynamic programming approach, using two arrays to track the minimum swaps required with or without swapping at each position.

## Implementation Details
- **Dynamic Programming Arrays**:
  - `swaps[i]`: Represents the minimum number of swaps required to make both sequences strictly increasing up to the `i`-th index, where the `i`-th elements are swapped.
  - `noSwaps[i]`: Represents the minimum number of swaps needed without swapping the `i`-th elements.
  - Initialize `swaps[0]` to `1` since swapping the first elements counts as one swap, and `noSwaps[0]` to `0` as no swap is needed initially.

- **Algorithm Logic**:
  - Iterate through both sequences from the second element to the end.
  - For each element at index `i`:
    - Check conditions for natural order (without swaps) and swapped order to decide if a swap is necessary or if continuing without swapping is feasible:
      - If elements at `i-1` and `i` in both sequences naturally maintain increasing order, update `swaps[i]` and `noSwaps[i]` based on the minimum swaps required from the previous position.
      - If only by swapping at `i` the sequences maintain order, adjust `swaps[i]` and `noSwaps[i]` to reflect this necessity.
  - Update the tracking arrays based on these conditions to reflect the minimum number of swaps required at each step.

- **Result Calculation**:
  - The final result is the minimum value between `swaps[n-1]` and `noSwaps[n-1]`, indicating the least swaps required to make the entire sequences increasing either by swapping or not swapping the last elements.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the length of the input sequences. The solution involves iterating through each index of the sequences exactly once.
- **Space Complexity**: `O(n)` due to the storage used by `swaps` and `noSwaps` arrays. Although this can be reduced to `O(1)` by only keeping track of values from the previous step and current step.

## Problem Link
For a detailed problem statement and constraints, visit [Minimum Swaps to Make Sequences Increasing](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/).

## Usage
```cpp
vector<int> nums1 = {1, 3, 5, 4};
vector<int> nums2 = {1, 2, 3, 7};
Solution solution;
int result = solution.minSwap(nums1, nums2);
// result will be 1, reflecting the minimum swaps needed to make both sequences strictly increasing.
