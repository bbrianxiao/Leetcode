# 751. IP to CIDR

## Overview
The `ipToCIDR` function in the `Solution` class converts an IP address to the smallest possible list of CIDR blocks that covers a given range of IPs, starting from the specified IP. This method uses bit manipulation to efficiently calculate the CIDR blocks.

## Implementation Details
- **String to Binary Representation**:
  - Converts an IP address string into a 32-bit binary representation. It splits the IP by dots, converts each segment to an integer, and accumulates it into a long integer by shifting and adding.

- **Helper Function `toCIDR`**:
  - Converts a 32-bit binary representation of an IP address into CIDR format. The function calculates the subnet mask based on the number of IPs (step size) that can be represented by the current CIDR block.
  - It uses bit manipulation to extract each of the four octets of the IP address and calculates the subnet mask by determining the highest power of two that fits into the step size.

- **Generate CIDR Blocks**:
  - Determines the smallest step by finding the lowest bit in the current IP address's binary representation that can cover part or all of the required range.
  - Adjusts the step size to not exceed the remaining number of IPs needed.
  - For each step, generates a CIDR block using the `toCIDR` function, increments the IP address by the step size, and decreases the count of IPs needed accordingly.

## Time and Space Complexities
- **Time Complexity**: O(N), where N is the number of CIDR blocks generated. Each block calculation involves constant time operations.
- **Space Complexity**: O(1).

## Problem Link
For a detailed problem statement and constraints, visit [IP to CIDR](https://leetcode.com/problems/ip-to-cidr/).

## Usage
```cpp
Solution solution;
string ip = "255.0.0.7";
int range = 10;
vector<string> result = solution.ipToCIDR(ip, range);
// result will contain the CIDR blocks covering from IP "255.0.0.7" to "255.0.0.16"
