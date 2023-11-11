#include <iostream>

using namespace std;

void solution() {
    int T, A, B, cnt;

    cin >> T;
    while (T--) {
        cin >> A >> B;
        cnt = 2 * B - A;
        cout << cnt << ' ' << B - cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}