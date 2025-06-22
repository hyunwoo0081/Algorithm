#include <iostream>
#define MOD 14579

using namespace std;

int main() {
    long long a, b, result = 1;
    
    cin >> a >> b;
    for (; a <= b; a++) {
        result = (result * a*(a+1)/2) % MOD;
    }
    cout << result;

    return 0;
}