#include <iostream>

using namespace std;

void solution() {
    int T, t, a;

    cin >> T;
    while (T--) {
        cin >> t;
        for (a = 1; a + a*a <= t; a++);
        a--;
        cout << a << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}