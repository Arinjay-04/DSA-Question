#include <bits/stdc++.h>
using namespace std;


bool checkRotation(string s1 , string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    if(n1 != n2){
        return false; 
    }

    queue<char> q1;
    for(int i=0; i<n1; i++){
        q1.push(s1[i]);
    }

    queue<char> q2;
    for(int i=0; i<n2; i++){
        q2.push(s2[i]);
    }
    
    int count = 0;

    while(count < n2){
       char x = q2.front();
       q2.pop();
       q2.push(x);
       count++;
       if(q1 == q2){
        return true;
       }
       
       
    }
   return false;
}


int main(){
    
     string str1 = "AACD", str2 = "ACDA";
 
    if (checkRotation(str1, str2))
        cout<<"Strings are rotations of each other"<<endl;
    else
        cout<<"Strings are not rotations of each other"<<endl;

return 0;
}