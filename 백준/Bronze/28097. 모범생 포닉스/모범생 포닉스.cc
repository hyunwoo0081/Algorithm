#include <iostream>

using namespace std;

int main() {
    long long T, N, cnt;
    
    cin >> T;
    cnt = (T-1) * 8;
    while (T--) {
        cin >> N;
        cnt += N;
    }
    
    cout << (long long) cnt / 24 << ' ' << cnt % 24;

    return 0;
}