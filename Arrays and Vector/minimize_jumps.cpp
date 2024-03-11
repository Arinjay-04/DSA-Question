// Given an array of N integers arr[] where each element represents the maximum length of the jump that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
public:
    int minJumps(int arr[], int n) {
        int jump = 0;
        int i = 0;
        int j = 0;
        int k = -1;

        if (arr[0] == 0) {
            return -1; // If the first element is 0, cannot proceed.
        }

        if (n == 1) {
            return 0; // If there is only one element, no jump is required.
        }

        while (i < n - 1) {
            // Check if the current element is 0 and if it's possible to jump over it
            

            k = max(k, arr[i] + i);
            
           
            if (k >= n - 1) {
                jump++;
                return jump; // Reached the end of the array
            }

            if (i == j) {
                jump++;
                j = k;
            }
            
            
            
            i++;
            
            if(i>j){
                return -1;
            }
            
        }
        return -1; // If it's not possible to reach the end of the array
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends