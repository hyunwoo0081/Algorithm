#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    while (a || b) {
        a -= b;
        
        if (a <= 1) {
            cout << "0 0\n";
        }
        else if (a % 2) {
            cout << a/2-1 << ' ' << "1\n";
        }
        else {
            cout << a/2 << ' ' << "0\n";
        }
        
        cin >> a >> b;
    }

    return 0;
}