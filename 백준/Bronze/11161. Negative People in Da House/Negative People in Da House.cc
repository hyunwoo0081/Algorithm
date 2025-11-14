#include <iostream>

using namespace std;

int main() {
    int T, M, a, b, r, s;
    
    cin >> T;
    while (T--) {
        r = s = 0;
        cin >> M;
        while (M--) {
            cin >> a >> b;
            s += a - b;
            r = min(r, s);
        }
        cout << -r << '\n';
    }

    return 0;
}