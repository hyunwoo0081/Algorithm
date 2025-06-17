#include <iostream>

using namespace std;

int main() {
    long long T, N;
    
    cin >> T;
    while (T--) {
        cin >> N;
        cout << (N*(N+1)*(2*N+1)/6) << '\n';
    }

    return 0;
}