#include <iostream>

using namespace std;

int main() {
    long long a, b, c, N;
    
    a = b = 0;
    c = 1;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        a = b;
        b = c;
        c = a + b;
    }
    
    cout << 2*(2*b+a);

    return 0;
}