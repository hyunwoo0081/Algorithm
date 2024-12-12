#include <iostream>

using namespace std;

int main() {
    int X, Y, rx, ry, N;
    
    cin >> X >> Y;
    N = (min(X, Y)-1) / 2;
    
    rx = N;
    ry = N;
    X -= 2*N;
    Y -= 2*N;
    
    if (X == 1)
        ry += Y-1;
    else if (Y == 1)
        rx += X-1;
    else
        ry++;
    
    cout << rx << ' ' << ry;

    return 0;
}