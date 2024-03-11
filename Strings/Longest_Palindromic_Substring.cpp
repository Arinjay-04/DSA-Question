//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  

    string longestPalin (string S) {
        
        
        int start = 0;
        int maxlength = 1;
        int n = S.length();
        
        for(int i=1; i<n ; i++){
            
            //Even 
            int l = i-1;
            int r = i;
            
            while(l>=0 && r<n && S[l] == S[r]){
                if(r-l+1 > maxlength){
                    maxlength = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
            
            l = i-1;
            r = i+1;
            
            while(l>=0 && r<n && S[l] == S[r]){
                if(r-l+1 > maxlength){
                    maxlength = r - l + 1;
                    start = l;
            }
             l--;
                r++;
        }
        }
        
        return S.substr(start, maxlength);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
