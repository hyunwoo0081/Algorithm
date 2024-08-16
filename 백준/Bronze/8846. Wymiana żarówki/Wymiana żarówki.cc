#include <iostream>
#define MOD 500000009
#define MUL 4

using namespace std;

int main() {
    long long result, r, N;
    
    result = 0;
    r = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        result = (result + r) % MOD;
        r = (r * MUL) % MOD;
    }
    
    cout << result;

    return 0;
}