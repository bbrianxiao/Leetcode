# 443. String Compression

## Overview
The `compress` function in the `Solution` class efficiently compresses a list of characters in-place by reducing consecutive sequences of the same character to that character followed by the number of repetitions, if the number is greater than one. The function then returns the new length of the array.

## Implementation Details
- **In-Place Compression**:
  - The function uses two pointers:
    - `i` to iterate through the original list and count consecutive characters.
    - `k` to update the list in-place with the compressed version.
  - The current character (`currentChar`) and its count are tracked as the list is processed.

- **Compression Logic**:
  - Loop through `chars` using `i` to identify sequences of the same character.
  - Increment `i` while characters match `currentChar` to count occurrences.
  - Store `currentChar` at `chars[k]` and increment `k`.
  - If the count of `currentChar` is greater than 1, convert the count to a string and append each digit to `chars` at subsequent positions of `k`.
  - After processing a sequence, continue from the new position of `i`.

## Time and Space Complexities
- **Time Complexity**: O(N), where N is the number of characters in the input list. The entire list is traversed once for counting and once for compressing.
- **Space Complexity**: O(1) because the compression is done in-place using the existing `chars` array with no additional space proportional to the input size used.

## Problem Link
For a detailed problem statement and constraints, visit [String Compression](https://leetcode.com/problems/string-compression/).

## Usage
```cpp
Solution solution;
vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
int compressedLength = solution.compress(chars);
// The chars array becomes {'a', '2', 'b', '2', 'c', '3'} and compressedLength is 6
