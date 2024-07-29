# 140. Word Break II

## Overview
The `wordBreak` function in the `Solution` class returns all possible sentences that can be formed by concatenating words from a dictionary `wordDict` such that the resulting sentence is exactly the string `s`. This function uses a Trie structure for efficient prefix matching and backtracking to generate possible sentences.

## Implementation Details
- **Trie Data Structure**:
  - A Trie is used to store the dictionary words, enabling efficient word prefix searches.
  - The `TrieNode` class contains an array `next[26]` to store child nodes and a boolean `isEnd` that indicates if the node corresponds to the end of a dictionary word.

- **Building the Trie**:
  - Each word in the `wordDict` is inserted into the Trie. For each character in the word, navigate or create the corresponding child node until the end of the word is reached, then mark it as an end node.

- **Depth-First Search (DFS) with Backtracking**:
  - Starting from each character in the string `s`, use the Trie to check if the current segment is a valid word.
  - If a valid word is found, recursively attempt to form the rest of the sentence.
  - If the end of the string `s` is reached during this process, add the formed sentence to the result list `retval`.
  - Use a current path string `temp` to maintain the sentence being formed as the recursion progresses.

- **Sentence Formation**:
  - As valid words are identified using the Trie, they are appended to `temp` separated by spaces.
  - When the end of the string is reached and a valid sentence has been formed, it is added to the list of results `retval`.

## Time and Space Complexities
- **Time Complexity**: `O(n * m + L)`, where `n` is the length of the string `s`, `m` is the average length of words in `wordDict`, and `L` is the total number of solutions. The complexity depends heavily on the number of possible sentences that can be formed.
- **Space Complexity**: `O(t + k)`, where `t` is the total space used by the Trie to store all words in `wordDict`, and `k` is the maximum depth of the recursion stack. Each recursive call might involve creating a substring, contributing further to space usage.

## Problem Link
For a detailed problem statement and constraints, visit [Word Break II](https://leetcode.com/problems/word-break-ii/).

## Usage
```cpp
string s = "catsanddog";
vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
Solution solution;
vector<string> sentences = solution.wordBreak(s, wordDict);
// sentences will include "cats and dog", "cat sand dog"
