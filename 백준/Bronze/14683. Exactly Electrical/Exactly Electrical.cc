#include <iostream>

using namespace std;

int main() {
    int X1, Y1, X2, Y2, t, l;
    
    cin >> X1 >> Y1 >> X2 >> Y2 >> t;
    l = abs(X1-X2) + abs(Y1-Y2);
    if (t-l < 0 || (t-l)%2)
        cout << 'N';
    else
        cout << "Y";

    return 0;
}