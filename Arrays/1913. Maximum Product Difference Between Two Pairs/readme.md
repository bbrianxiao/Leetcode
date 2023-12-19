# Max Product Difference Between Two Pairs

This C++ solution is designed to compute the maximum product difference between two pairs of numbers in an array. The approach focuses on identifying the two largest and two smallest numbers in the array and then calculating the product difference between these pairs.

## Implementation Details

- **Efficient Traversal**: The algorithm iterates through the `nums` array once, performing constant time operations at each iteration.
- **Tracking Extremes**: It keeps track of the two largest and two smallest numbers in the array. This is achieved by comparing each element in the array with the current largest and smallest values and updating them accordingly.
- **Optimized Comparisons**: The comparison logic ensures that the largest and second-largest, as well as the smallest and second-smallest numbers, are correctly identified by the end of a single pass through the array.

## Time and Space Complexities

- **Time Complexity**: The time complexity of this algorithm is `O(n)`, where `n` is the number of elements in the array. This is because the algorithm needs to iterate through the array only once.
- **Space Complexity**: The space complexity is `O(1)` as the solution uses a fixed amount of space regardless of the input array size.

## Usage

```cpp
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // Implementation details
    }
};

// Example Usage
Solution solution;
vector<int> nums = {5, 6, 2, 7, 4};
int result = solution.maxProductDifference(nums);
// result now holds the maximum product difference
