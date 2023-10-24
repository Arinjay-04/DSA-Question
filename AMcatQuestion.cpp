// 1) Problem: There is a colony of 8 cells arranged in a straight line where each
// day every cell competes with its adjacent cells(neighbour). Each day, for each
// cell, if its neighbours are both active or both inactive, the cell becomes inactive
// the next day, otherwise it becomes active the next day.
// Assumptions: The two cells on the ends have single adjacent cell, so the other
// adjacent cell can be assumed to be always inactive.
// Even after updating the cell state. consider its previous state for updating the
// state of other cells. Update the cell information of all cells simultaneously.
// Write a function cellCompete which takes takes one 8 element array of integers
// cells representing the current state of 8 cells and one integer days representing
// te number of days to simulate.
// An integer value of 1 represents an active cell and value of 0 represents an
// inactive cell.


#include<iostream>
using namespace std;

void counting(int array[9]){
    
    
    int new_array[9];
    
    
    if(array[1]==0){
        new_array[0]= 0;
    }
    else{
        new_array[0]= 1;
    }
    
    if(array[7]==0)
    {
        new_array[8]= 0;
    }
    else{
        new_array[8]= 1;
    }
    
    for(int i=1; i<=7; i++){
        if(array[i-1] == array[i+1]){
            new_array[i] = 0;
        }
        else{
            new_array[i]=1;
        }
    }
    
    for(int i=0; i<9; i++){
        cout<<new_array[i]<<"";
    }
}

int main(){
    int array[9]={0,1,0,0,0,1,1,1,0};
    counting(array);
    return 0;
}
