// 74. Search a 2D Matrix
// Solved
// Medium
// Topics
// Companies
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.


class Solution {
public:
    bool BinarySearch(vector<int>& v, int target) {
        int low = 0;
        int high = v.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  

            if (v[mid] == target) {  
                return true;
            } else if (target < v[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool ans = false;

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] <= target && matrix[i][m - 1] >= target) {
                // if (BinarySearch(matrix[i], target)) {
                //     return true;  
                // }
                ans = BinarySearch(matrix[i], target);
            }
        }

        return ans;
    }
};
