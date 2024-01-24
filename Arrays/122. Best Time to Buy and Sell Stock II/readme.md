# 122. Best Time to Buy and Sell Stock II

## Overview
The `maxProfit` function finds the maximum profit that can be made by buying and selling a single stock. Given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day, it calculates the maximum profit that can be achieved from a single transaction (buying one and selling one share of the stock).

## Implementation Details
- The function initializes two variables: `mini` to track the minimum stock price so far and `maxDiff` to track the maximum profit.
- It iterates over the `prices` array.
- For each price, the function updates `mini` if a lower stock price is found.
- It calculates the profit if the stock is sold on the current day (current price minus `mini`) and updates `maxDiff` if this profit is greater than the current maximum.
- The function returns `maxDiff`, representing the maximum profit that can be obtained.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of elements in the `prices` array. The function iterates through the array once.
- **Space Complexity**: `O(1)`, as it uses a constant amount of space.

## Problem Link
For a detailed problem statement and constraints, visit [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/).

## Usage
```cpp
Solution solution;
vector<int> prices = {7, 1, 5, 3, 6, 4};
int result = solution.maxProfit(prices);
// result will be 5, indicating the maximum profit from buying at price 1 and selling at price 6.
