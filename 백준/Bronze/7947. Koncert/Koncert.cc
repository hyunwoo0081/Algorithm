#include <iostream>

using namespace std;

void solution() {
    int T, r, g, b, R, G, B;

    cin >> T;
    while (T--) {
        r = g = b = 0;
        for (int i = 0; i < 10; i++) {
            cin >> R >> G >> B;
            r += R, g += G, b += B;
        }

        cout << (int)(r/10. + .5) << ' ' << (int)(g/10. + .5) << ' ' << (int)(b/10. + .5) << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}