#include <iostream>

using namespace std;

void solution() {
    int T = 1;
    double l, ro, t, dist;

    cin >> l >> ro >> t;
    while (ro != 0.) {
        cout << fixed;
        cout.precision(2);

        dist = l * 3.1415926535 * ro / 63360;

        cout << "Trip #" << T << ": ";
        cout << dist << ' ' << dist * 3600/t << '\n';

        cin >> l >> ro >> t;
        T++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}