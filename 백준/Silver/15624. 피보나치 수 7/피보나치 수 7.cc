#include <iostream>
#define DIV 1'000'000'007

using namespace std;

int main() {
    long long a, b, c, N;
    
    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    else if (N == 1 || N == 2) {
        cout << 1;
        return 0;
    }
    
    N -= 2;
    a = 0;
    b = c = 1;
    while (N--) {
        a = b;
        b = c;
        c = (a + b) % DIV;
    }
    
    cout << c;

    return 0;
}