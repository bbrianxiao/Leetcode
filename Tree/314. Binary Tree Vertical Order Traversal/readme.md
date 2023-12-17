# Binary Tree Vertical Order Traversal

The Binary Tree Vertical Order Traversal algorithm is designed to traverse a binary tree and organize the nodes' values based on their vertical distances from the root. This traversal produces a set of lists, each representing a vertical line from top to bottom in the tree.

## Implementation Details

- **Breadth-First Search (BFS)**: The algorithm uses a BFS approach to ensure nodes are visited level by level.
- **Queue with Level Information**: A queue is employed to store nodes along with their corresponding vertical levels during traversal.
- **Map for Vertical Ordering**: A map (or similar associative container) is used to group node values by their vertical levels.
- **Handling Left and Right Children**: For each node, the left child is considered at one level less than the current, and the right child at one level more.
- **Order Preservation**: The order of nodes at the same vertical level and depth is preserved as they are encountered.

## Time and Space Complexities

- **Time Complexity**: The overall time complexity is `O(N)`, where `N` is the number of nodes in the tree. Each node is processed once in the BFS.
- **Space Complexity**: The space complexity is also `O(N)`. The queue and map together may hold all nodes of the tree in the worst-case scenario.
