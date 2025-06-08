#include <iostream>

using namespace std;

int main() {
    int T, a, b, N;
    
    cin >> T;
    while (T--) {
        cin >> a >> b >> N;
        cout << "Data set: " << a << ' ' << b << ' ' << N << '\n';
        
        while (N--) {
            if (a > b)
                a /= 2;
            else
                b /= 2;
        }
        
        if (a < b) {
            N = a;
            a = b;
            b = N;
        }
        
        cout << a << ' ' << b << "\n\n";
    }

    return 0;
}