#include <iostream>

using namespace std;

void solution() {
    int N, a, b, target;

    cin >> N >> a >> b;
    while (N || a || b) {
        target = N / 2 + 1;
        N -= a + b;

        if (a + N < target)
            cout << -1;
        else if (a >= target)
            cout << 0;
        else
            cout << target - a;
        cout << '\n';

        cin >> N >> a >> b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}