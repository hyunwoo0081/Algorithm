#include <iostream>

using namespace std;

int main() {
    long long N, A, B, a, b, tmp;
    
    cin >> N >> A >> B;
    a = b = 1;
    while (N--) {
        a += A;
        b += B;
        
        if (a < b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        
        if (a == b) {
            b--;
        }
    }
    
    cout << a << ' ' << b;

    return 0;
}