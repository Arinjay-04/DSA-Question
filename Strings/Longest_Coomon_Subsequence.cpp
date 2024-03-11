#include <bits/stdc++.h>
using namespace std;

string Fucnt(int n , int m , string &s1 , string &s2){
    if(n<0 || m<0){
        return " ";
    }

    if(s1[n] == s2[m]){
        return   Fucnt(n-1, m-1 , s1,s2 ) + s1[n];
    }

    return max(Fucnt(n-1, m , s1 , s2) , Fucnt(n, m-1, s1 ,s2));
}


string  LCS(string s1 , string s2){
      
      int n = s1.size();
      int m = s2.size();

      return Fucnt(n , m , s1 ,s2);
}


int main(){

    string s1 = "aaaabbaa";
    string s2 = "aabbaaaa";

    string ans = LCS(s1 , s2);

    cout<<ans<<endl;


return 0;
}