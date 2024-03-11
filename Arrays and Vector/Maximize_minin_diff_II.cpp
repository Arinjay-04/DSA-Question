// Given an array arr[] denoting heights of N towers and a positive integer K.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

// You can find a slight modification of the problem here.
// Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        // vector<int> v1;
        
        // for(int i=0; i<n ; i++){
        //     v1.push_back(arr[i]);
        // }
        
        // sort(v1.begin(), v1.end());
        
        // vector<int> v;
        
        // for(int i=0; i<n-3; i++){
        //     int ans = v1[i] + k;
        //     v.push_back(ans);
        // }
        
        // for(int i= n-3 ; i<n ; i++ ){
        //     int ans = v1[i] - k;
        //     v.push_back(ans);
        // }
        
        // int ans = v[n-1] - v[0];
        
        // return ans;
        
         sort(arr, arr+n);
        
    //     for(int i=0; i<n; i++){
    //         if(arr[i] - k < 0){
    //             arr[i] += k;
    //         }
    //         else{
    //             arr[i] -= k;
    //         }
    //     }
        
      
       
    //   int ans = arr[n-1] - arr[0];
       
    //   return ans;
    
    int ans = arr[n-1] - arr[0];
    
    int maxi = arr[n-1]; 
    int mini = arr[0] ;
    
    for(int i=0; i<n-1; i++){
        maxi = max( arr[n-1] - k,  arr[i]+k  );
        mini = min(  arr[0] + k, arr[i+1]-k);
        
        if(mini<0){
            continue;
        }
        ans = min(maxi - mini , ans);
    }
    
    return ans;
       
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends