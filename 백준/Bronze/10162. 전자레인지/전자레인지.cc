#include <iostream>

using namespace std;

void solution() {
    int T, a = 300, b = 60, c = 10;

    cin >> T;
    if (T % 10 == 0)
        cout << T/a << ' ' << (T - T/a*a) / b << ' ' << (T - T/b*b) / c;
    else
        cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}