#include <iostream>

using namespace std;

int notPrimes[1000] = {true};

int main() {
    int n, r;
    
    for (int i = 2; i < 1000; i++) {
        for (int j = 2; j*i < 1000; j++) {
            notPrimes[i*j] = true;
        }
    }
    
    cin >> n;
    cout << n << ' ';
    r = 0;
    for (int i = 0; i < n; i++) {
        while (notPrimes[++r]);
        cout << r << ' ';
    }

    return 0;
}