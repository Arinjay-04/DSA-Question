class Solution {
public:
    vector<int> quickSort(vector<int> &nums){
        int n = nums.size();
        if(n<=1){
            return nums;
        }
        int pivot = nums.back();
        vector<int> left;
        vector<int> right;

        for(int i=0; i<n-1; i++){
            if(nums[i] < pivot){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }

        left = quickSort(left);
        right = quickSort(right);

        left.push_back(pivot);
        left.insert(left.end(), right.begin(), right.end());


        return left;
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans = quickSort(nums);
        nums = ans;
        return nums;
    }
};



///////  OPTIMAL QUICKSORT USING TWO POINTERS ////////////

class Solution {
public:
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start]; // Choose the pivot element
        int i = start + 1;
        int j = end;

        // Loop until the two indices meet
        while (i <= j) {
            // Find elements that are out of place
            while (i <= end && nums[i] <= pivot) {
                i++;
            }
            while (j > start && nums[j] > pivot) {
                j--;
            }

            // Swap elements to correct their position
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        // Place pivot in its correct position
        swap(nums[start], nums[j]);
        return j;
    }

    void QuickSort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int part = partition(nums, start, end);
            QuickSort(nums, start, part - 1); // Sort the left part
            QuickSort(nums, part + 1, end);   // Sort the right part
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
