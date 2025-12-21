#include <iostream>

using namespace std;

int main() {
    int N, C, p, d, v, r = 987654321;
    
    cin >> N >> C;
    while (N--) {
        cin >> p >> d >> v;
        r = min(r, p + d + v*C);
    }
    
    cout << r;

    return 0;
}