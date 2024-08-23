# 2131. Longest Palindrome by Concatenating Two-Letter Words

## Overview
The `longestPalindrome` function in the `Solution` class finds the longest palindrome that can be formed by concatenating two-letter words from a given list. The function uses a hash map to count occurrences of each word, and then strategically pairs words to maximize the length of the resulting palindrome.

## Implementation Details
- **Word Count**:
  - A hash map `count` is used to store the frequency of each two-letter word in the input list.
  
- **Palindrome Formation**:
  - Iterate through each unique word in the hash map:
    - For words that are self-palindromic (e.g., "aa", "bb"), these can be placed in the middle of the palindrome. If there's an odd count of such words, one can be used as a center pivot.
    - For other words, attempt to pair them with their reverse (e.g., "ab" with "ba"). The number of such pairs is limited by the minimum count of the original and reversed words.
    
- **Palindrome Calculation**:
  - For self-palindromic words, add either their full count (if no center pivot word has been used) or their count minus one (to save one as a potential center if the count was odd).
  - For non-self-palindromic pairs, add the minimum count of the word and its reverse to the total palindrome length.
  - The total length is multiplied by 2 to account for both halves of the palindrome. If a single center pivot word was used, it adds an extra 2 to the length.

## Time and Space Complexities
- **Time Complexity**: O(N + W), where N is the number of words in the input list and W is the number of unique words processed in the hash map. Constructing the hash map is O(N), and the subsequent processing is O(W).
- **Space Complexity**: O(W), where W is the number of unique words stored in the hash map.

## Problem Link
For a detailed problem statement and constraints, visit [Longest Palindrome by Concatenating Two-Letter Words](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/).

## Usage
```cpp
Solution solution;
vector<string> words = {"lc","cl","gg"};
int result = solution.longestPalindrome(words);
// result will be 6, as "lcclgg" or "ggcllc" are possible palindromes
