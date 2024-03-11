// Chef has 
// �
// A marbles, and his friend has 
// �
// B. They want to redistribute the marbles among themselves such that after redistributing:

// Chef and his friend both have at least one marble each; and
// The number of marbles with Chef is divisible by the number of marbles with his friend.
// What's the minimum number of marbles that need to be transferred from one person to another to achieve this?

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a, b;
	    cin>>a>>b;
	    //Cond_1 when a gives
	    int t1 = a;
	    int t2 = b;
	    int count_1= 0;
	    int count_2 = 0;
	    int flag=0;  // for condintion 2
	    while(t1%t2 != 0 || t2%t1 != 0){
	        t1--;
	        t2++;
	        count_1++;
	        
	        
	        //There can be some condition when the while loop terminates 
	        // 1. a%b =0 
	        // 2. when a ==0;
	        //so for checking cond 2;
	        if(t1%t2 == 0 || t1>t2){
	            flag = 1;
	        }
	        
	    }
	    //WHEN A IS THE GIVER
	    while(a%b !=0){
	        a++;
	        b--;
	        count_2++;
	    }
	    
	    if(flag == 1){
	       cout<< min(count_1, count_2) <<endl;
	    }
	    else{
	        cout<<count_2<<endl;
	    }
	}
	return 0;
}
