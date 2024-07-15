// 1717. Maximum Score From Removing Substrings
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s and two integers x and y. You can perform two types of operations any number of times.

// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.


            // MY APPROACH //////// WRONG //////////////

class Solution {
public:
    int helper1(string s, int x, int y ){
        int n = s.length();
        int count = 0;
        stack<char> st;
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top() == 'a' && s[i] == 'b'){
                st.pop();
                count += x;
            }else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            int temp = st.top();
            st.pop();                         
            if( !st.empty() && temp == 'a' &&  st.top() == 'b'){ // THe error here is by removing the ba from 
                count += y;                                      // I am not check if ba will still be repeated
                st.pop();                                        // Like how I am doing in above example
            }
           
        }

        return count;
    }


    int helper2(string s, int x, int y ){
        int n = s.length();
        int count = 0;
        stack<char> st;
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top() == 'b' && s[i] == 'a'){
                st.pop();
                count += y;
            }else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            int temp = st.top();
            st.pop();
            if( !st.empty() && temp == 'b' &&  st.top() == 'a'){
                count += x;
                st.pop();
            }
           
        }

        return count;
    }



    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int count = 0;
        if(x > y){
            count = helper1(s, x, y);
        }
        else{
            count = helper2(s, x, y);
        }

        return count;
    }
}; 



                  /// SOLUTION //////////////////////


class Solution {
public:
    // Helper function for removing 'ab' pairs first
    int helper1(string s, int x, int y) {
        int n = s.length();
        int count = 0;
        stack<char> st;
        
        // First pass to remove 'ab' pairs
        for(int i = 0; i < n; i++) {
            if(!st.empty() && st.top() == 'a' && s[i] == 'b') {
                st.pop();
                count += x;
            } else {
                st.push(s[i]);
            }
        }

        // Second pass to remove 'ba' pairs from the remaining characters
        string remaining;
        while(!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        for(int i = 0; i < remaining.length(); i++) {
            if(!st.empty() && st.top() == 'b' && remaining[i] == 'a') {
                st.pop();
                count += y;
            } else {
                st.push(remaining[i]);
            }
        }
        
        return count;
    }

    // Helper function for removing 'ba' pairs first
    int helper2(string s, int x, int y) {
        int n = s.length();
        int count = 0;
        stack<char> st;
        
        // First pass to remove 'ba' pairs
        for(int i = 0; i < n; i++) {
            if(!st.empty() && st.top() == 'b' && s[i] == 'a') {
                st.pop();
                count += y;
            } else {
                st.push(s[i]);
            }
        }

        // Second pass to remove 'ab' pairs from the remaining characters
        string remaining;
        while(!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        for(int i = 0; i < remaining.length(); i++) {
            if(!st.empty() && st.top() == 'a' && remaining[i] == 'b') {
                st.pop();
                count += x;
            } else {
                st.push(remaining[i]);
            }
        }
        
        return count;
    }

    // Main function to decide which helper function to use
    int maximumGain(string s, int x, int y) {
        // Choose the order of removal based on which gain is higher
        if(x > y) {
            return helper1(s, x, y);
        } else {
            return helper2(s, x, y);
        }
    }
};