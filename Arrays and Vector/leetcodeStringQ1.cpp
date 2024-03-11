//LEETCODE QUESTION ON FIND THE LONGEST PALINDROME IN A GIVEN SUBSTRING 
// STILL INCOMPLETE  

class Solution {
public:

    string solve(string& s1, string& s2, int i, int j, vector<vector<string>>& dp) {
        if (i == s1.length() || j == s2.length()) {
            return "";
        }
        if (dp[i][j] != "") {
            return dp[i][j];
        }

        string ans;
        if (s1[i] == s2[j]) {
            ans = s1[i] + solve(s1, s2, i + 1, j + 1, dp);
        }
        else {
            string option1 = solve(s1, s2, i + 1, j, dp);
            string option2 = solve(s1, s2, i, j + 1, dp);

           // ans = (option1.length() > option2.length()) ? option1 : option2;
           if((option1.length() > option2.length())){
               return ans = option1;
           }
           else{
               return ans = option2;
           }
        }

        return dp[i][j] = ans;
    }

    string longestPalindrome(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        vector<vector<string>> dp(s.length(), vector<string>(revStr.length(), ""));
        
        string result = solve(s, revStr, 0, 0, dp);
        return result;
    }
};
