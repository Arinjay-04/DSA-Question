// 2191. Sort the Jumbled Numbers

// Medium

// You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

// The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

// You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

// Notes:

// Elements with the same mapped values should appear in the same relative order as in the input.
// The elements of nums should only be sorted based on their mapped values and not be replaced by them.
 

// Example 1:

// Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
// Output: [338,38,991]
// Explanation: 
// Map the number 991 as follows:
// 1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
// 2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
// Therefore, the mapped value of 991 is 669.
// 338 maps to 007, or 7 after removing the leading zeros.
// 38 maps to 07, which is also 7 after removing leading zeros.
// Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
// Thus, the sorted array is [338,38,991].



class Solution {
public:
    int reverseDigits(int num) {
        int rev_num = 0;            //FUNCTION TO REVERSE THE DIGITS OF A NUMBER 
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mp;
        unordered_map<int, int> mp1;
        for(int i=0; i<n; i++){
            mp1[nums[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            int originalNum = nums[i];   
            int x = 0;
            int count = 0;
            
            if (originalNum == 0) {
                x = mapping[0];
            } else {
                while (originalNum > 0) {
                    x = x * 10 + mapping[originalNum % 10];
                    if (x == 0) {
                        count++;
                    }
                    originalNum /= 10;
                }
                
                x = reverseDigits(x);
                
                while (count > 0) {
                    x = x * 10;
                    count--;
                }
            }
            
            mp.push_back({nums[i], x});
        }
        
        
        sort(mp.begin(), mp.end(), [&mp1](auto& a, auto& b) {
            if (a.second != b.second) {  
                return a.second < b.second;
            }
            return mp1[a.first] < mp1[b.first];
        });
        for (auto it : mp) {
            cout << it.first << " " << it.second << endl;
        }
        
        vector<int> ans;
        for (auto it : mp) {
            ans.push_back(it.first);
        }
        
        return ans;
    }
};



// Lambda Function Definition:

// [](auto& a, auto& b) { ... } defines a lambda function that takes two parameters a and b. These parameters represent the elements being compared during sorting.
// Capture List:

// [&mp1] captures the variable mp1 by reference, allowing the lambda function to access the mp1 unordered map.
// Comparing Transformed Values:

// if (a.second != b.second) { return a.second < b.second; }
// a and b are pairs where a.second and b.second are the transformed values of the numbers.
// This line checks if the transformed values of a and b are different.
// If they are different, it returns true if a.second is less than b.second, and false otherwise. This ensures that the pair with the smaller transformed value comes first.
// Comparing Original Indices:

// return mp1[a.first] < mp1[b.first];
// If the transformed values are the same (i.e., a.second == b.second), the function falls back to this line.
// a.first and b.first are the original numbers.
// mp1 is an unordered map that stores the original index of each number.
// This line returns true if the original index of a.first is less than the original index of b.first, and false otherwise. This ensures stable sorting by the original indices when the transformed values are equal.