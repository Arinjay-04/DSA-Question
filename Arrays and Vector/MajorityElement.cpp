// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority 
// element always exists in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int > mp;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){
            if(it.second > (nums.size()-1)/2){
                ans = it.first;
            }
        }

        return ans;
    }
};


     OR A SMART APPROACH



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[(nums.size()-1)/2];        /// The element will always appear in the middle of sorted vector
    }
};
