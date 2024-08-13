// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void BFS (int row, int col, const vector<vector<char>>& matrix, const string& word, int post, int dir_r, int dir_c, int &count ){
    int n = matrix.size();
    int m = matrix[0].size();
    if(post == word.length()){
        count++;
        return;
    }
    int nrow = row+dir_r;
    int ncol = col+dir_c;
    if(nrow >= 0 && nrow <n && ncol >= 0 && ncol<m){
    if(matrix[nrow][ncol] == word[post]){
        BFS(nrow, ncol, matrix, word, post+1, dir_r, dir_c , count);
    }
    }
}
int countOccurrences(const vector<vector<char>>& matrix, const string& word){
    vector<pair<int, int>> dir = {{-1,-1}, {-1,0},{-1,1}, {0,-1}, {0,0}, {0,1}, {1,-1}, {1, 0}, {1,1}};
    int n = matrix.size();
    int m = matrix[0].size();
    int count =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == word[0]){
                for(auto it: dir){
                    int nrow = i+it.first;
                    int ncol = j+it.second;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == word[1]) {
                         if(matrix[nrow][ncol] == word[1]){
                        BFS(nrow, ncol, matrix, word, 2, it.first, it.second, count);
                    }
                    }
                   
                    
                }
            }
        }
    }
    return count;
}


int main() {
    vector<vector<char>> matrix = {
    {'A', 'B', 'C', 'E'},
    {'S', 'C', 'C', 'S'},
    {'A', 'D', 'E', 'E'}
};

string word = "ABC";

int result = countOccurrences(matrix, word);


cout<<result<<endl;


    return 0;
}