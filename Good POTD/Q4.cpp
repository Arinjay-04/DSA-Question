// 40. Combination Sum II
// Solved
// Medium
// Topics
// Companies
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.


class Solution {
public:
    void back_track(int idx, vector<int>& main, int target, int& sum,
                    vector<int>& temp, set<vector<int>>& ans) {
        if (sum == target) {
            ans.insert(temp);
            return;
        }
        if (sum > target || idx >= main.size()) {
            return;
        }

        // if(i >= main.size()){
        //     return ans;
        // }

        for (int i = idx;  i < main.size(); i++) {
            if (i > idx && main[i] == main[i - 1]) {
                continue;
            }

            temp.push_back(main[i]);
            sum += main[i];
            back_track(i + 1, main, target, sum, temp, ans);
            temp.pop_back();
            sum -= main[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        while (candidates.size() > 0 && candidates.back() > target) {
            candidates.pop_back();
        }

        vector<vector<int>> xyz;
        if (candidates.size() == 0) {
            return xyz;
        }

        int n = candidates.size();

        vector<int> temp;
        set<vector<int>> ans;
        int sum = 0;

        if (candidates.empty()) {
            return {{}};
        }

        back_track(0, candidates, target, sum, temp, ans);

        // set<set<int>> st;
        // int i=0;
        // while(i <n){
        //     int j = i;
        //     int temp = target - candidates[j];

        // }

        vector<vector<int>> result(ans.begin(), ans.end());

        return result;
    }
};