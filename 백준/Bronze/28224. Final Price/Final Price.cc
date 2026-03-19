#include <iostream>

using namespace std;

int main() {
    long long N, a, r=0;
    
    cin >> N;
    while (N--) {
        cin >> a;
        r += a;
    }
    cout << r;

    return 0;
}