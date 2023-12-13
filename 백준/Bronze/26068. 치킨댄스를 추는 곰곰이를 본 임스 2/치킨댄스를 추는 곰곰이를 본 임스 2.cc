#include <iostream>

using namespace std;

void solution() {
    char c, d;
    long long T, a, cnt = 0;

    cin >> T;
    while (T--) {
        cin >> c >> d >> a;
        cnt += a <= 90;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}