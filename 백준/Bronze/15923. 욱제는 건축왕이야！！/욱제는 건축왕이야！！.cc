#include <iostream>

using namespace std;

int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int T, firstX, firstY, prevX, prevY, x, y, result= 0;
    
    cin >> T >> firstX >> firstY;
    T--;
    prevX = firstX;
    prevY = firstY;
    
    while (T--) {
        cin >> x >> y;
        
        result += abs(x - prevX) + abs(y - prevY);
        
        prevX = x;
        prevY = y;
    }
    result += abs(x - firstX) + abs(y - firstY);
    
    cout << result;

    return 0;
}