#include <iostream>

using namespace std;

void solution() {
    int T, h, m;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> h >> m;

        m -= 45;
        if (m < 0)
            h--;
        m = (60 + m) % 60;
        h = (24 + h) % 24;

        cout << "Case #" << t << ": " << h << ' ' << m << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}