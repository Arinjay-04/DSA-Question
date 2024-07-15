// 1190. Reverse Substrings Between Each Pair of Parentheses
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

 

// Example 1:

// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:

// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.


class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int i=0;
        while( i<s.length()){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                int top = st.top();
                st.pop();
                reverse(s.begin()+top+1 , s.begin()+i);
            }
            
             i++;
        }

         s.erase(remove(s.begin(), s.end(), '('), s.end());
        s.erase(remove(s.begin(), s.end(), ')'), s.end());   // To erase prenthsis from the string we can't directly 
                                                            // use the for loop as it will skip some index;


            // can alson be written as 


        //     int i1=0;
        // while(i1< s.length()){
        //     if(s[i1] == ')' || s[i1] == '('){
        //         s.erase(s.begin()+i1);
        //         i1 = i1-1;
        //     }
        //     i1++;
        // }
         
        return s;

    }
};