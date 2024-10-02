
// 624. Maximum Distance in Arrays



///////////////////////GREEDY///////////////////////////////////////////


class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        
        int mini = arrays[0][0];
        int maxi = arrays[0].back();

        // int min_dis = INT_MAX;
        int max_dis = INT_MIN;

        for(int i=1; i<n; i++){
            max_dis = max(max_dis, abs(arrays[i].back() - mini));
            max_dis = max(max_dis, abs(arrays[i][0] - maxi));
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }


        return max_dis;
    }
};