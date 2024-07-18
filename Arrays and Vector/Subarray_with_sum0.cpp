// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Examples:

// Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
// Output: 5
// Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.



class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int, int> mp;
        int maxi = 0;
        int sum =0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0){
                maxi = i+1;
            }else{
                if(mp.find(sum) != mp.end()){
                    maxi = max(maxi, i - mp[sum]);
                }else{
                    mp[sum] = i;
                }
            }
        }
        
        return maxi;
    }
};