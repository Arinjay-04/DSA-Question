#include<iostream>
using namespace std;

int counting(int array[5]){

    int ans=0;  

    for(int i=0; i<=5; i++){
        for(int j=0; j<array[i]/2; j++){
            if(array[i]== j*j){
                 ans++;
            }
        }
    }
    return ans;
}

int main(){
    int array[5]={25,49,79,89,81};
    cout<<counting(array)<<endl;

    return 0;
}