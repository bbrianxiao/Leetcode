# 249. Group Shifted Strings

## Overview
The `groupStrings` function in the `Solution` class groups strings where each string can be shifted to become another in the group. A shift for the string "abc" -> "bcd" is done by moving each character by the same number of steps in the alphabet.

## Implementation Details
- **Hashing Function**:
  - The `hashFunc` method generates a unique hash for each string based on its character shifts relative to the first character.
  - For each pair of consecutive characters in the string, it calculates the difference modulo 26 (to wrap around the alphabet) and then converts this difference into a character. This character string serves as the hash key.
- **Grouping Strings**:
  - The `groupStrings` function initializes a hash map to store groups of strings that share the same hash.
  - For each string in the input list, it computes its hash using `hashFunc` and adds the string to the corresponding group in the map.
  - It then collects all groups from the hash map into the final result list.

## Time and Space Complexities
- **Time Complexity**: `O(N * L)` where `N` is the number of strings and `L` is the average length of the strings. The complexity arises as each string is processed character by character to compute the hash.
- **Space Complexity**: `O(N * L)` for storing the strings in the hash map and the result list. The size of the hash keys and lists depends on the number of strings and their lengths.

## Problem Link
For a detailed problem statement and constraints, visit [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/).

## Usage
```cpp
vector<string> strings = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
Solution solution;
vector<vector<string>> groups = solution.groupStrings(strings);
// groups will contain [["abc","bcd","xyz"], ["az","ba"], ["acef"], ["a","z"]]
