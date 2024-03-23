#include <iostream>

using namespace std;

void solution() {
    int a, b, T, x, cnt = 0;

    cin >> a >> b >> T;
    while (T--) {
        cin >> x;
        cnt += a <= x && x <= b;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}