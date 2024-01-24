# 134. Gas Station

## Overview
The `canCompleteCircuit` function determines if there is a starting gas station at which a vehicle can complete a circuit around a circular route. The route consists of gas stations where `gas[i]` is the amount of gas at station `i`, and `cost[i]` is the cost of gas needed to travel from station `i` to the next station. The function returns the index of the starting gas station if the circuit can be completed, or `-1` if it is not possible.

## Implementation Details
- The function iterates over each gas station, calculating the current gas level (`currgas`) and the total gas balance (`totalgas`).
- `currgas` is updated at each station based on the gas obtained and the cost to reach the next station.
- If `currgas` falls below zero at any point, the current station cannot be the starting point, and the search moves to the next station (`maxStart` is updated).
- `totalgas` accumulates the overall gas balance for the entire circuit.
- After completing the loop, if `totalgas` is negative, it means the circuit cannot be completed from any station, and `-1` is returned.
- If `totalgas` is non-negative, `maxStart` is the index of the starting station that allows completing the circuit.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of gas stations. Each station is visited once.
- **Space Complexity**: `O(1)`, as the solution uses a constant amount of space.

## Problem Link
For a detailed problem statement and constraints, visit [Gas Station](https://leetcode.com/problems/gas-station/description/).

## Usage
```cpp
Solution solution;
vector<int> gas = {1, 2, 3, 4, 5};
vector<int> cost = {3, 4, 5, 1, 2};
int result = solution.canCompleteCircuit(gas, cost);
// result will be the index of the starting gas station, if the circuit can be completed.
