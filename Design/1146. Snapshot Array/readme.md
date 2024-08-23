# 1146. Snapshot Array

## Overview
The `SnapshotArray` class implements a data structure that allows for capturing snapshots of an array at different points in time. It supports setting values at specific indices, taking a snapshot, and querying the value at an index as of a specific snapshot.

## Implementation Details
- **Data Structures**:
  - A vector of vectors, `snapshot`, where each element is a vector of pairs. Each pair consists of a snapshot ID and the value of the array element at that index during the snapshot.
  - An integer `snap_id` to keep track of the current snapshot number.

- **Constructor (`SnapshotArray`)**:
  - Initializes the `snapshot` array with the specified `length`, populating each position with an initial value of 0 at snapshot ID 0.

- **Set Method (`set`)**:
  - Adds or updates the value at the specified `index` to the `val` in the current snapshot. It pushes the pair of the current snapshot ID and the value onto the snapshot list of the specified index.

- **Snap Method (`snap`)**:
  - Increments and returns the current snapshot ID. This effectively marks the boundary for the next set of changes to begin on a new snapshot.

- **Get Method (`get`)**:
  - Retrieves the value at the specified `index` as of the given `snap_id`. It uses binary search (`upper_bound`) to find the first entry in the snapshot history of the index that has a snapshot ID greater than the requested snapshot ID, then steps back to get the actual value at or before the requested snapshot.

## Time and Space Complexities
- **Time Complexity**:
  - `set`: O(1), since appending to a vector takes constant time.
  - `snap`: O(1), increments and returns an integer.
  - `get`: O(log S), where S is the number of snapshots, due to the binary search in the snapshot history.
- **Space Complexity**: O(N * S), where N is the number of elements in the array and S is the average number of modifications to any element before taking a snapshot.

## Problem Link
For a detailed problem statement and constraints, visit [Snapshot Array](https://leetcode.com/problems/snapshot-array/).

## Usage
```cpp
SnapshotArray snapshotArray(3); // Create a snapshotArray with length 3
snapshotArray.set(0, 5); // Set index 0 to 5
int snapId = snapshotArray.snap(); // Take a snapshot, returns 0
snapshotArray.set(0, 6);
int val = snapshotArray.get(0, snapId); // Get the value at index 0 with snapshot id 0, should return 5
