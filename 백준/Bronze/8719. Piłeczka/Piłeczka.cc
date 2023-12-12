#include <iostream>

using namespace std;

void solution() {
    long long T, a, b, cnt;

    cin >> T;
    while (T--) {
        cin >> a >> b;

        cnt = 0;
        while (a < b) {
            a *= 2;
            cnt++;
        }

        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}