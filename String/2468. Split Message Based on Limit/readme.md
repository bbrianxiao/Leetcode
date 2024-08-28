# 2468. Split Message Based on Limit

## Overview
The `splitMessage` function in the `Solution` class splits a given string `message` into multiple parts where each part is constrained by a given character limit `limit`. The parts are formatted to include pagination in the form of `<part_number/total_parts>`, ensuring each part adheres to the length limit including the pagination metadata.

## Implementation Details
- **Pagination Calculation**:
  - Calculate the maximum possible length of a part considering the metadata that needs to be included.
  - This metadata consists of the pagination format `<part_number/total_parts>`, which has a dynamic length depending on the number of parts and their numbering.
  
- **Dynamic Part Length Determination**:
  - The function calculates the necessary length for each part dynamically based on the maximum number of digits required to represent the total parts (`len`).
  - Iterates over possible lengths (`len`) for the total number of parts and determines the feasible configuration.

- **Part Creation (`get` function)**:
  - Iteratively splits the message into parts based on the calculated maximum part length including the pagination metadata.
  - Each part is initially appended with an incomplete pagination tag and finalized in a subsequent step.
  
- **Finalizing Pagination**:
  - After determining all parts and their initial pagination, the total number of parts is known and used to complete the pagination formatting.

## Time and Space Complexities
- **Time Complexity**: O(N + M), where N is the length of the message and M is the number of parts created. Each character of the message is processed once, and additional time is spent adjusting the pagination.
- **Space Complexity**: O(M), where M is the number of message parts generated. This accounts for the storage of each message part in the output list.

## Problem Link
For more information, visit [Split Message Based on Limit](https://leetcode.com/problems/split-message-based-on-limit/)

## Usage
```cpp
Solution solution;
string message = "Example very long message needing split";
int limit = 20;
vector<string> parts = solution.splitMessage(message, limit);
// parts will contain several strings where each respects the limit including pagination metadata
