# 1136. Parallel Courses

## Overview
The `minimumSemesters` function calculates the minimum number of semesters required to complete `n` courses, given a list of prerequisite course relations. Each relation is a pair of courses, where the second course depends on the first one. The function returns the minimum number of semesters needed to complete all courses, or `-1` if it is impossible to complete all courses.

## Implementation Details
- The function constructs an adjacency list (`adjList`) to represent the course dependency graph and a vector (`course`) to track the number of prerequisite courses for each course.
- It uses a queue to implement a Breadth-First Search (BFS) algorithm.
- Courses with no prerequisites are added to the queue initially.
- The function processes the queue by semesters. In each semester, it removes courses from the queue (these courses have no remaining prerequisites) and decreases the prerequisite count for courses that depend on them.
- If a course's prerequisite count drops to zero, it is added to the queue for the next semester.
- The BFS continues until there are no more courses to process.
- If there are courses with unsatisfied prerequisites (non-zero count in `course`), it returns `-1`. Otherwise, it returns the total number of semesters.

## Time and Space Complexities
- **Time Complexity**: `O(V + E)`, where `V` is the number of courses (vertices in the graph) and `E` is the number of prerequisite relations (edges in the graph).
- **Space Complexity**: `O(V + E)`, for storing the adjacency list and the prerequisite count vector.

## Problem Link
For a detailed problem statement and constraints, visit [Parallel Courses](https://leetcode.com/problems/parallel-courses/).

## Usage
```cpp
Solution solution;
int n = 3;
vector<vector<int>> relations = {{1, 3}, {2, 3}};
int result = solution.minimumSemesters(n, relations);
// result will be the minimum number of semesters to complete all courses
