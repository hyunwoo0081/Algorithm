#include <iostream>

using namespace std;

int main() {
    int T, N, mod;
    
    cin >> T;
    while (T--) {
        cin >> N;
        
        mod = N % 100;
        if ((N+1) % mod == 0)
            cout << "Good\n";
        else
            cout << "Bye\n";
    }

    return 0;
}