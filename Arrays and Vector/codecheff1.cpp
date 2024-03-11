// ou are trying to be more healthy, and thus have decided to eat only fruits. You have lots of fruits of different types, but you get bored of a specific fruit type very quickly — so you will never repeat fruit types that you eat, i.e. you will eat at most one fruit of each type.

// You have 
// �
// N fruits, the 
// �
// i-th fruit being of type 
// �
// �
// A 
// i
// ​
//   and providing you a nutrition value of 
// �
// �
// B 
// i
// ​
//  .
// Some fruits are rotten, so 
// �
// �
// B 
// i
// ​
//   can be negative.

// Find the maximum possible sum of nutrition values of the fruits you eat, under the constraint of never repeating fruit types.
// Note that you may choose to eat no fruits as well, which would give you 
// 0
// 0 nutrition.



#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(){

    int n;
    cin>>n;
    vector<int> v1;
    vector <int> v2;

    for(int i=0; i<n ;i++){
        int a ;
        cin>>a;
        v1.push_back(a);
    }

    for(int i=0; i< n ; i++)
{
    int a ;
    cin>>a;
    v2.push_back(a);
}

map <int , int> m;

for(int i=0 ;i< n; i++){
    m[v1[i]] = max(m[v1[i]], v2[i]);
}

int sum =0;

for(auto it = m.begin(); it != m.end(); ++it){
    sum += it->second;
}

cout<<sum<<endl;

return 0;
}