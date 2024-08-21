# 146. LRU Cache

## Overview
The `LRUCache` class implements a Least Recently Used (LRU) caching mechanism. It supports two primary operations: `get` and `put`. The cache has a predefined capacity, and when adding new elements that would cause the capacity to be exceeded, the least recently used item is evicted from the cache.

## Implementation Details
- **Data Structures**:
  - `unordered_map<int, Node*> cache`: Maps keys to node pointers in a doubly linked list which stores the value and order of access.
  - `Node` structure: Represents an element in the cache, containing the key, value, and pointers to the previous and next nodes.
  - `head` and `tail` pointers: Dummy head and tail nodes of the doubly linked list to simplify boundary conditions.

- **Constructor**:
  - Initializes the cache with the given capacity and creates dummy head and tail nodes. Links the head and tail to denote an empty list.

- **Get Operation** (`get`):
  - If the key exists in the cache:
    - The corresponding node is moved to the front of the doubly linked list to mark it as most recently used.
    - Returns the value of the node.
  - If the key does not exist, returns `-1`.

- **Put Operation** (`put`):
  - If the key is already in the cache:
    - The existing node is updated with the new value and moved to the front of the list.
  - If the key is new:
    - A new node is created and added to the front of the list.
    - If adding this node exceeds the capacity:
      - The least recently used node (just before the tail) is removed from both the linked list and the map.
  - Incorporates logic to handle insertion and deletion in the doubly linked list to maintain the LRU order.

- **Helper Functions**:
  - `add(Node* node)`: Inserts a node right after the dummy head node.
  - `remove(Node* node)`: Removes a node from its position in the linked list.

## Time and Space Complexities
- **Time Complexity**:
  - Both `get` and `put` operations have O(1) time complexity due to the use of hash map for direct access to nodes and linked list for O(1) addition and removal.
- **Space Complexity**:
  - O(capacity) due to the storage of up to 'capacity' node elements in the doubly linked list and hash map.

## Problem Link
For a detailed problem statement and constraints, visit [LRU Cache](https://leetcode.com/problems/lru-cache/).

## Usage
```cpp
LRUCache cache(2); // Capacity of the cache

cache.put(1, 1);  // Cache is {1=1}
cache.put(2, 2);  // Cache is {1=1, 2=2}
cout << cache.get(1);    // returns 1 and makes 1 most recently used

cache.put(3, 3);  // Evicts key 2, Cache is {1=1, 3=3}

cout << cache.get(2);    // returns -1 (not found)
cache.put(4, 4);  // Evicts key 1, Cache is {4=4, 3=3}
cout << cache.get(1);    // returns -1 (not found)
cout << cache.get(3);    // returns 3
cout << cache.get(4);    // returns 4
