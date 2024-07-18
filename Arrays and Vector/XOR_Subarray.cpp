// Given an array of integers A and an integer B.

// Find the total number of subarrays having bitwise XOR of all elements equals to B.



// Problem Constraints
// 1 <= length of the array <= 105

// 1 <= A[i], B <= 109



// Input Format
// The first argument given is the integer array A.

// The second argument given is integer B.



// Output Format
// Return the total number of subarrays having bitwise XOR equals to B.



// Example Input
// Input 1:

//  A = [4, 2, 2, 6, 4]
//  B = 6
// Input 2:

//  A = [5, 6, 7, 8, 9]
//  B = 5


int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> mp;
    int count = 0;
    int x = 0;
    
    for(int i=0; i<n; i++){
        x ^= A[i];
        if(x == B){
            count ++;
        }
            if(mp.find(x^B) != mp.end()){
                count += mp[x^B];               
            }
                mp[x] ++;
    }
    
    return count;
}
