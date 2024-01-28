# 359. Logger Rate Limiter

## Overview
The `Logger` class implements a rate-limiter for logging messages. The `shouldPrintMessage` method checks if a message should be printed based on the following rule: A message with a unique identifier (string) should be printed at most once every 10 seconds.

## Implementation Details
- The Logger class has a map `m` that associates messages with their next allowed timestamp.
- The `shouldPrintMessage` method:
  - Checks if the message has been encountered before.
  - If not, the message is added to the map with its next allowed timestamp (current timestamp + 10), and the method returns `true`.
  - If the message exists in the map, it compares the current timestamp with the allowed timestamp in the map:
    - If the current timestamp is greater or equal, the message can be printed again, the allowed timestamp is updated, and the method returns `true`.
    - If the current timestamp is less, the method returns `false`, indicating the message should not be printed.

## Time and Space Complexities
- **Time Complexity**: `O(1)` for each call to `shouldPrintMessage`, assuming map operations are O(1) on average.
- **Space Complexity**: `O(N)`, where `N` is the number of unique messages that have arrived within the past 10 seconds.

## Problem Link
For a detailed problem statement and constraints, visit [Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/).

## Usage
```cpp
Logger* logger = new Logger();
bool isPrinted1 = logger->shouldPrintMessage(1, "foo"); // returns true
bool isPrinted2 = logger->shouldPrintMessage(2, "bar"); // returns true
bool isPrinted3 = logger->shouldPrintMessage(3, "foo"); // returns false
