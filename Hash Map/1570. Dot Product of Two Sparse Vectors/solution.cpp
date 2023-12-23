// Time complexity: O(n) for creating the Hash Map; O(L) for calculating the dot product
// Space Complexity: O(L) for creating the Hash Map. O(1) for calculating the dot product.
// Idea: Initialize a map to store the non-zero elements with its corresponding index

class SparseVector {
public:
    unordered_map<int, int> m;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                m[i] = nums[i];
            }
        }
    }
    
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for (auto& c : m) {
            if (vec.m.find(c.first) != vec.m.end()) {
                result += c.second * vec.m[c.first];
            }
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);