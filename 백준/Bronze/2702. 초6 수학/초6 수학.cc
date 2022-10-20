#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int tmp;

    if (a > b)
        swap(a, b);
    while (a > 0) {
        tmp = b % a;
        b = a;
        a = tmp;
    }

    return b;
}

void solution() {
    int T, g, a, b;

    cin >> T;
    while (T--) {
        cin >> a >> b;
        g = gcd(a, b);
        cout << a*b/g << ' ' << g << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
