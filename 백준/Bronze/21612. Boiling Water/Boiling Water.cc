#include <iostream>

using namespace std;

int main() {
    int b, p;
    
    cin >> b;
    p = 5*b - 400;
    
    cout << p << '\n';
    cout << (p == 100 ? 0 : p < 100 ? 1 : -1);

    return 0;
}