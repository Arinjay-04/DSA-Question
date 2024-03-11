//  logicians walk into a bar. The bartender asks them, "Does everyone want a beer?".
// Logician 1 replies "I don't know".
// Then, logician 2 replies "I don't know".
// Finally, logician 3 replies "Yes".

// Now, coming to the actual problem.
// �
// N logicians numbered 
// 1
// ,
// 2
// ,
// …
// ,
// �
// 1,2,…,N walk into a bar.
// You are given a binary string 
// �
// S where 
// �
// �
// =
// 1
// S 
// i
// ​
//  =1 if and only if the 
// �
// i-th logician wants beer for himself, otherwise 
// �
// �
// =
// 0
// S 
// i
// ​
//  =0.

// Note that the logicians don't know the string 
// �
// S — each one only knows whether they themself want a beer.
// They are also perfect logicians, and hence can extract information from hearing what the previous logicians reply.

// The bartender asks them, "Does everyone want a beer?".
// Predict what will be the replies of logician 
// 1
// ,
// 2
// ,
// …
// ,
// �
// 1,2,…,N if they reply in that order.

// Once again, note that logician 
// �
// i only has the following information:

// �
// �
// S 
// i
// ​
//  , i.e, whether he himself wants a beer or not; and
// The replies of logicians 
// 1
// ,
// 2
// ,
// 3
// ,
// …
// ,
// �
// −
// 1
// 1,2,3,…,i−1.
// Output "IDK" for "I Don't know", "YES" or "NO" with their respective meanings.

//SO the conditions are the last element will be yess and the between will be idk only is there is no zero presen else all wil be no;
// As the bartender is asking "Does everyone want a beer"? --> the first logician don't know the answer of other logicians and wants to drink the beer so he will say "IDK" --> --> the second logician don't know the answer of other logicians and wants to drink the beer and he knows the answer of 1st logician which is "IDK", so he will also say "IDK"

// -->this goes on until either one of the logician says "NO"{that he do not wants a beer} or we reach the last logician.

// --> if there is a "NO" the next logician will say "NO" as now not everyone wants beer and so on all other logicians afterwards will say NO.

// -->else if we reach the last logician and everyone have said "YES" for drink and "IDK" if everyone wants beer. Hence, he will say "YES" everyone wants beer.












#include <iostream>
#include <string>
using namespace std;


int main(){

    int n;
    cin>>n;
     string s;
    cin>>s;

    bool found = false;

    for(int i=0; i< n-1; i++){
        if(s[i] == '0'){
            cout<<"NO"<<endl;
            found = true;
        }

        else if(s[i] == '1' && found == false){
            cout<<"IDK"<<endl;
        }
        else if(s[i] == '1' && found == true){
            cout<<"NO"<<endl;
        }

    }

    if(s[n-1] == '1' && found == false){
        cout<<"YESS"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


return 0;
}