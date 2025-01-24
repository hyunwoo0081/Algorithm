#include <iostream>

using namespace std;

int main() {
    int A, P1, R, P2;
    
    cin >> A >> P1 >> R >> P2;
    
    cout << ((double) A / P1 < 3.1415926535*R*R/P2 ? "Whole pizza" : "Slice of pizza");

    return 0;
}