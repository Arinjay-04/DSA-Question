// 1636. Sort Array by Increasing Frequency
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
//  If multiple values have the same frequency, sort them in decreasing order.

// Return the sorted array.

 

// Example 1:

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        // priority_queue<pair<int, int>> pq;
        // for(auto it : mp) {
        //     pq.push({it.second, it.first});
        // }

        
        vector<pair<int, int>> v(mp.begin(), mp.end());
        // while(!pq.empty()) {
        //     auto it = pq.top();
        //     pq.pop();
        //     v.push_back({it.second, it.first});
        // }

       
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {   // method to sort vector based on its second value
            return a.second == b.second ? a.first > b.first : a.second < b.second;        // if the second value is same then sort according to first value
        });

        vector<int> ans;
        for(auto it : v) {
            for(int i = 0; i < it.second; i++) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};


 [](const pair<int, int>& a, const pair<int, int>& b) {   // method to sort vector based on its second value
            return a.second == b.second ? a.first > b.first : a.second < b.second;        // if the second value is same then sort according to first value
        });


// This the lambda function used for sorting ///