15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j,
// i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int j=i+1;
            int k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    k--;
                }
                else if(sum <0){
                    j++;
                }else{
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                }
            }
        }

        vector<vector<int>> result(ans.begin(), ans.end());

        return result;

    }
};

