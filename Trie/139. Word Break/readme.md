# 139. Word Break

## Overview
The `wordBreak` function in the `Solution` class determines if a string `s` can be segmented into a space-separated sequence of one or more dictionary words provided in `wordDict`. The solution utilizes a Trie data structure for efficient prefix matching and memoization to avoid redundant checks.

## Implementation Details
- **Trie Data Structure**:
  - A Trie (prefix tree) is used to store the dictionary words. This allows for quick prefix searches and word validation.
  - The `TrieNode` class has an array `next[26]` representing child nodes for each letter of the alphabet and a boolean `isEnd` to mark the end of a word.

- **Insert Words into Trie**:
  - Words from `wordDict` are inserted into the Trie. For each character in a word, navigate or create a new node in the Trie until the end of the word is reached, then set the `isEnd` flag.

- **Depth-First Search (DFS) with Memoization**:
  - The main function uses a DFS approach, starting from the beginning of string `s`, trying to match prefixes in the Trie.
  - If a complete word is found in the Trie, recursively attempt to process the remainder of the string.
  - Use a memoization array `memo` to record positions in the string that have been visited and determined not to lead to a solution, optimizing the search process by pruning branches.

- **Dynamic Exploration**:
  - Starting from any position in the string `s`, explore forward and attempt to match continuous segments against the Trie.
  - If the end of the string is reached during one of these explorations, return true.
  - If a path does not yield a valid segmentation, mark it in the memoization array to avoid future reprocessing of the same segment.

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the length of the string `s` and `m` is the length of the longest word in `wordDict`. Each position in the string could potentially explore forward up to `m` characters repeatedly.
- **Space Complexity**: `O(t + n)`, where `t` is the total space used by the Trie to store the dictionary and `n` is used by the memoization array. The Trie space complexity depends on the number of nodes and the number of characters in all words.

## Problem Link
For a detailed problem statement and constraints, visit [Word Break](https://leetcode.com/problems/word-break/).

## Usage
```cpp
string s = "leetcode";
vector<string> wordDict = {"leet", "code"};
Solution solution;
bool canSegment = solution.wordBreak(s, wordDict);
// canSegment will be true as "leetcode" can be segmented into "leet code".
