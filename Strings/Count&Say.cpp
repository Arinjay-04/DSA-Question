// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.



class Solution {
public:
    string countAndSay(int n) {
       string s = "1";
       int i=1;

       while(i<n){
           string s1;
           int count = 1;
           for(int j=0; j<s.length(); j++){
               if(s[j] == s[j+1]){
                  count++;
               }
               else{
                   s1 += to_string(count) + s[j];
                   count = 1;
               }
           }
           i++;
           s = s1;
       }

       return s;

    }
};