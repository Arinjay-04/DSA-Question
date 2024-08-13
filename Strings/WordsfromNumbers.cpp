// 273. Integer to English Words
// Solved
// Hard
// Topics
// Companies
// Hint
// Convert a non-negative integer num to its English words representation.

 

// Example 1:

// Input: num = 123
// Output: "One Hundred Twenty Three"
// Example 2:

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


class Solution {
public:
    vector<string> number{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> Teens{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> Tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};


    string Hundred(long long n) {
         long long var = n % 100;
        string tens;
        if (var >= 10 && var < 20) {
            tens = Teens[var - 10];
        } else {
            if (var >= 20) {
                tens = Tens[var / 10];
                if (var % 10 > 0) {
                    tens += " " + number[var % 10];
                }
            } else {
                tens = number[var];
            }
        }

        string hundreds = n >= 100 ? number[n / 100] + " Hundred" : "";
        return hundreds + (hundreds.empty() || tens.empty() ? "" : " ") + tens;
    }

    string Billions(long long n) {
        if (n == 0) {
            return "";
        }
        string millions = Hundred(n);
        return millions + " Billion";
    }

    string Millions(long long n) {
        if (n == 0) {
            return "";
        }
        string millions = Hundred(n);
        return millions + " Million";
    }

    string Thousands(long long n) {
        if (n == 0) {
            return "";
        }
        string thousands = Hundred(n);
        return thousands + " Thousand";
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string result;

        long long billions = num / 1000000000;
        long long millions = (num / 1000000) % 1000;
        long long thousands = (num / 1000) % 1000;
        long long hundreds = num % 1000;

        if (billions > 0) {
            result += Billions(billions);
        }

        if (millions > 0) {
            result += (result.empty() ? "" : " ") + Millions(millions);
        }

        if (thousands > 0) {
            result += (result.empty() ? "" : " ") + Thousands(thousands);
        }

        if (hundreds > 0) {
            result += (result.empty() ? "" : " ") + Hundred(hundreds);
        }

        // Remove leading or trailing spaces
        if (result[0] == ' ') {
            result = result.substr(1);
        }
        if (result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
