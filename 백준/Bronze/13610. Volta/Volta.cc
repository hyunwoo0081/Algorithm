#include <iostream>

using namespace std;

int main() {
    int A, B, t;
    
    cin >> A >> B;
    t = B-A;
    
    cout << B / t + (B % t > 0);

    return 0;
}