// 1605. Find Valid Matrix Given Row and Column Sums
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements 
// of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

// Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

// Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> ans(n, vector<int> (m, 0));
        int i=0, j=0;
        while(i < n && j<m){
            int mini = min(rowSum[i], colSum[j]); // find the minimum pf that row and column and subtract it from the remainming
            ans[i][j] = mini;
            rowSum[i] -= mini;
            colSum[j] -= mini;

            if(rowSum[i] == 0){
                i++;
            }
            if(colSum[j] == 0){
                j++;
            }
        }

        return ans;
    }
};
