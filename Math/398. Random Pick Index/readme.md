# 398. Random Pick Index

## Overview
The `Solution` class provides a method, `pick`, which selects a random index from an array where the element at that index matches a given target value. This method employs reservoir sampling to ensure each index is selected with equal probability.

## Implementation Details
- **Constructor**:
  - The constructor takes an array of integers and stores it in the instance variable `nums`.
- **Pick Method**:
  - The `pick` function iterates through the stored array, using reservoir sampling to randomly select an index where the element matches the target. 

## Reservoir Sampling
Reservoir sampling is ideal for scenarios where the population size is unknown or is too large to handle in memory. The procedure for the `pick` method is as follows:
- Initialize a counter `count` to track the number of times the target has been encountered.
- Traverse each element of the array.
- For each occurrence of the target, increment `count`.
- Generate a random number and if this number is `0` (which has a probability of `1/count`), update the chosen index to the current index. This ensures that every index is picked with equal probability.

### Mathematical Explanation:
When the first target value is encountered (let's call this at index `i`), it is chosen with probability `1/1` (since `count` is 1).
When the second occurrence is found (at index `j`), the probability of choosing it is `1/2`, while the probability of still choosing the first occurrence becomes `1/2 * 1 = 1/2`.
For the `k`-th occurrence:
- The probability that it is chosen is `1/k`.
- The probability that any previous `k-1` occurrences are chosen adjusts such that each one up to the `k`-th has a `1/k` chance.

This ensures that by the end of the array traversal, each occurrence of the target has an equal probability of `1/n` (where `n` is the total number of target occurrences in the array) of being chosen.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of elements in the array. The function needs to traverse the entire array to ensure each instance of the target has an equal chance of being selected.
- **Space Complexity**: `O(1)`, since no additional space proportional to the input size is used beyond the initial storage of the array.

## Problem Link
For a detailed problem statement and constraints, visit [Random Pick Index](https://leetcode.com/problems/random-pick-index/).

## Usage
```cpp
vector<int> nums = {1, 2, 3, 3, 3};
Solution* solution = new Solution(nums);
int index = solution->pick(3);  // Randomly returns an index of '3' in nums, each index should have equal probability of returning.
