# 981. Time Based Key-Value Store

## Overview
The `TimeMap` class implements a time-based key-value data store that allows setting and retrieving values according to specific timestamps. Each operation involves associating a value with a key at a given timestamp, and fetching the most recent value for a key up to a certain timestamp.

## Implementation Details
- **Data Structure**:
  - A `map` named `m` is used where the key is an integer representing the timestamp, and the value is an unordered map that maps string keys to string values.
  - This structure allows efficient temporal queries and updates as each timestamp is associated with its own dictionary of keys and values.

- **Constructor**:
  - Initializes the TimeMap object without any special configuration.

- **Set Method (`set`)**:
  - Stores the `value` associated with a `key` at a specific `timestamp`.
  - Inserts the key-value pair into the map corresponding to the given timestamp in the `m` map.

- **Get Method (`get`)**:
  - Retrieves the value associated with the `key` at the most recent timestamp up to and including `timestamp`.
  - Iterates over the map in reverse order (starting from the most recent timestamp) to find the most recent value associated with the key that is not later than the given timestamp.
  - If the key is found at an appropriate timestamp, returns the corresponding value. Otherwise, returns an empty string indicating no matching key-value pair was found.

## Time and Space Complexities
- **Time Complexity**:
  - `set`: O(log n), where `n` is the number of distinct timestamps, as inserting into a map requires logarithmic time.
  - `get`: O(m), where `m` is the number of timestamps that are checked.
- **Space Complexity**: O(p), where `p` is the total number of key-value pairs stored across all timestamps.

## Problem Link
For a detailed problem statement and constraints, visit [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/).

## Usage
```cpp
TimeMap* timeMap = new TimeMap();
timeMap->set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1
cout << timeMap->get("foo", 1);  // returns "bar"
cout << timeMap->get("foo", 3);  // returns "bar" because there is no value corresponding to "foo" at timestamp 3, and 1 is the closest timestamp less than or equal to 3

timeMap->set("foo", "bar2", 4);
cout << timeMap->get("foo", 4);  // returns "bar2"
cout << timeMap->get("foo", 5);  // returns "bar2" as per the timestamp 4 which is the nearest to 5
