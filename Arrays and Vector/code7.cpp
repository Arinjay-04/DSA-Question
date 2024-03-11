//You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

//NOTE: WHENEVER WE HAVE GIVEN TO FIND UNIQUE ELEMENTS FROM A ARRAY OR VECTOR. INSTEAD OF APPENDING THEM IN VECTOR USE SET.
//SET DONOT ALLOW REPITITION OF ELEMENTS


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;
 
int main() {
    ll n;
    cin >> n;
 
 
     vector<int> arr(n);
 
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
 
    set<int> unique_ele(arr.begin(), arr.end()); // Unique Elements of the vector will be appended in set.
 
    cout<<unique_ele.size()<<endl;
 
    return 0;
}


//NOTE: WHENEVER WE HAVE GIVEN TO FIND UNIQUE ELEMENTS FROM A ARRAY OR VECTOR. INSTEAD OF APPENDING THEM IN VECTOR USE SET.
//SET DONOT ALLOW REPITITION OF ELEMENTS
