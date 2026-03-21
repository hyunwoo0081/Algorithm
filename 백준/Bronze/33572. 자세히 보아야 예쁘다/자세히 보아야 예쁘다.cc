#include <iostream>

using namespace std;

int main() {
    long long N, M, a, s=0;
    
    cin >> N >> M;
    while (N--) {
        cin >> a;
        s += a-1;
    }
    cout << (s >= M ? "DIMI" : "OUT");

    return 0;
}