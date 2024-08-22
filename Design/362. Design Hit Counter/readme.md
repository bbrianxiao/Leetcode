# 362. Design Hit Counter

## Overview
The `HitCounter` class implements a system to count the number of hits received in the past 5 minutes (300 seconds). The hits are recorded in real-time and the number of hits can be queried based on the current timestamp. The class uses a queue to efficiently manage the timestamps of each hit, ensuring that only relevant hits within the last 5 minutes are counted.

## Implementation Details
- **Queue Data Structure**:
  - The `queue<int>` holds timestamps of each hit. This ensures that the oldest timestamps (hits) are at the front of the queue and can be easily discarded when they are more than 5 minutes old.

- **Constructor**:
  - Initializes the `HitCounter` object without any special configuration.

- **Hit Method (`hit`)**:
  - Records a hit at a given timestamp by adding the timestamp to the queue.
  - After adding a new timestamp, it removes timestamps from the queue that are more than 5 minutes older than the current hit timestamp.

- **Get Hits Method (`getHits`)**:
  - Returns the number of hits in the last 5 minutes.
  - Similar to the `hit` method, it first removes all timestamps from the queue that are more than 5 minutes older than the current query timestamp before returning the count of timestamps left in the queue.

## Time and Space Complexities
- **Time Complexity**:
  - `hit`: O(1) on average for adding a timestamp to the queue. The cleaning part depends on the number of elements that need to be removed and can vary.
  - `getHits`: O(1) for accessing the size of the queue. The cleaning part can take longer depending on how many old timestamps are in the queue.
- **Space Complexity**: O(N), where `N` is the number of hits recorded in the last 300 seconds. This complexity reflects the maximum size of the queue.

## Problem Link
For a detailed problem statement and constraints, visit [Design Hit Counter](https://leetcode.com/problems/design-hit-counter/).

## Usage
```cpp
HitCounter* counter = new HitCounter();
counter->hit(1);       // hit at timestamp 1.
counter->hit(2);       // hit at timestamp 2.
counter->hit(300);     // hit at timestamp 300.
cout << counter->getHits(300);   // get hits at timestamp 300, should return 3.
cout << counter->getHits(301);   // get hits at timestamp 301, should return 2 as the hit at timestamp 1 is more than 300 seconds ago.
