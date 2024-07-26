
// Code


// Testcase
// Testcase
// Test Result
// 34. Find First and Last Position of Element in Sorted Array
// Solved
// Medium
// Topics
// Companies
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]




class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        int up =  upper_bound(nums.begin(), nums.end(), target)- nums.begin();

        if(lb<nums.size() && nums[lb] == target){
              return {lb, up-1};
        }
       
       return {-1, -1};
    }
};

/// FUnctions of upper and lower bound

int lowerBound(vector<int>& nums, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans = n;  // Initialize to n (end of the array) in case target is not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int upperBound(vector<int>& nums, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans = n;  // Initialize to n (end of the array) in case target is not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
