#include <iostream>

using namespace std;

int main() {
    int turn, prev, a[2];
    
    turn = 1;
    cin >> a[0] >> a[1];
    while (a[0] < 5 || a[1] < 5) {
        prev = turn;
        turn = (turn + 1) % 2;
        
        a[prev] += a[turn];
    }
    
    cout << (turn ? "yt" : "yj");

    return 0;
}