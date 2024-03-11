// Ben is fighting a monster with a health of 
// �
// H. He starts with an attack power of 
// 1
// 1.
// Ben has two types of moves:

// He can use a regular attack, which damages the monster by his current attack power.
// After this, his attack power doubles.
// He can use a special move: choose a prime number 
// �
// P such that 
// �
// ≤
// �
// P≤H (
// �
// H being the current health of the monster), and deal 
// �
// P damage to the monster.
// This move can be done at most once.
// Note that this special move doesn't affect his attack power: it doesn't double, and remains the same.
// To kill the monster, Ben must deal exactly 
// �
// H damage to it.
// Find the minimum number of moves needed for Ben to kill the monster, or print 
// −
// 1
// −1 if it's impossible to kill it no matter what.

#include <vector>
#include <cmath>
using namespace std;

bool check_prime(int h) {
    if (h <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(h); i++) {
        if (h % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        int count = 0;
        int a =1;
        while(h>0){
            if(check_prime(h)){
                h=0;
                count++;
                break;
            }
            else{
            h = h-a;
            a = a*2;
            count++;
            }
        }
        
        if(h!= 0){
            cout<<-1<<endl;
        }
        else{
            cout<<count<<endl;
        }
    }

    return 0;
}

