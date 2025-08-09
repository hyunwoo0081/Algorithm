#include <iostream>

using namespace std;

int main() {
    int N, a, b, c;
    
    cin >> N;
    a = b = 0;
    while (N > 0) {
        c = N/2 + N%2;
        a += c;
        N -= c;
        
        c = N/2 + N%2;
        b += c;
        N -= c;
    }
    
    cout << b << ' ' << a;

    return 0;
}