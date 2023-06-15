#include <iostream>

using namespace std;

void solution() {
    double a, sum, r;

    cin >> a;
    cout << fixed;
    cout.precision(2);
    while (a != 0) {
        sum = 0;
        r = 1;
        for (int i = 0; i < 5; i++) {
            sum += r;
            r *= a;
        }
        cout << sum << '\n';
        cin >> a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}