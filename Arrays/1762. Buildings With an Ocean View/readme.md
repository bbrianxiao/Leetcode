# 1762. Buildings With an Ocean View

## Implementation Details
- The `findBuildings` function identifies buildings that have an ocean view. Buildings have an ocean view if there are no taller buildings to their right.
- It accepts a vector `heights` representing the heights of the buildings.
- The function iterates from right to left since the ocean is assumed to be on the right.
- It uses `currmin` to track the height of the tallest building encountered so far.
- Buildings taller than `currmin` are added to the result as they have an ocean view.
- The result vector is reversed at the end to maintain the original order of buildings.
- The function returns a vector of indices representing buildings with an ocean view.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the number of buildings. The function requires a single pass through the vector.
- **Space Complexity**: `O(1)`, excluding the space used for the output. The algorithm uses a fixed amount of additional space (for `currmin` and loop index).

## Usage
```cpp
Solution solution;
vector<int> heights = {4, 2, 3, 1};
vector<int> oceanViewBuildings = solution.findBuildings(heights);
// oceanViewBuildings will contain indices of buildings with an ocean view
