// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long low, long long mid, long long high) {
    vector<long long> temp;
    long long inversions = 0;

    long long left = low;
    long long right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            inversions += (mid - left + 1); // Counting inversions
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (long long i = low, j = 0; i <= high; i++, j++) {
        arr[i] = temp[j];
    }

    return inversions;
}

long long mergeSort(long long arr[], long long low, long long high) {
    long long inversions = 0;

    if (low < high) {
        long long mid = low + (high - low) / 2;

        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid + 1, high);
        inversions += merge(arr, low, mid, high);
    }

    return inversions;
}

class Solution {
public:
    long long int inversionCount(long long arr[], long long N) {
        return mergeSort(arr, 0, N - 1);
    }
};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends