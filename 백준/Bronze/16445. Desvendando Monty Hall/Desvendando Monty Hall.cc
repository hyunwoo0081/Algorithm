#include <iostream>

using namespace std;

int main() {
    int T, N, r=0;
    cin >> T;
    while (T--) {
        cin >> N;
        r += N != 1;
    }
    cout << r;

    return 0;
}