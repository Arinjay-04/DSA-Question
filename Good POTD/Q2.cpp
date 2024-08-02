// 2134. Minimum Swaps to Group All 1's Together II
// Solved
// Medium
// Topics
// Companies
// Hint
// A swap is defined as taking two distinct positions in an array and swapping the values in them.

// A circular array is defined as an array where we consider the first element and the last element to be adjacent.

// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array
// together at any location.

 

// Example 1:

// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
// Explanation: Here are a few of the ways to group all the 1's together:
// [0,0,1,1,1,0,0] using 1 swap.
// [0,1,1,1,0,0,0] using 1 swap.
// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
// There is no way to group all 1's together with 0 swaps.
// Thus, the minimum number of swaps required is 1.



class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;

        // Count the number of 1's in the array
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                count1++;
            }
        }

        // If there are no 1's or the whole array is 1's, no swaps are needed
        if (count1 == 0 || count1 == n) return 0;

        // Initialize the sliding window
        int i = 0, j = 0;
        int mini = 0;

        // Calculate the number of 0's in the first window of size 'count1'
        for (j = 0; j < count1; j++) {
            if (nums[j] == 0) {
                mini++;
            }
        }
        
        int count0 = mini;
        j = j-1;
        // Iterate over the circular array
        for (int k = 0; k < n; k++) {
            // Reduce the count of 0's if the element leaving the window is 0
            if (nums[i] == 0) {
                count0--;
            }
            i = (i + 1) % n;
            j = (j + 1) % n;

            // Increase the count of 0's if the new element entering the window is 0
            if (nums[j] == 0) {
                count0++;
            }

            // Update the minimum number of 0's found in any window of size 'count1'
            mini = min(mini, count0);

            // Break the loop if we have completed one full circle
            if (i == 0) {
                break;
            }
        }
       
        return mini;
    }
};