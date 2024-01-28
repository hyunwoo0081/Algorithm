#include <iostream>

using namespace std;

void solution() {
    int a, b, c, m, result = 0, t;

    cin >> a >> b >> c;
    m = (a + b + c) / 3;

    t = m - a;
    a += t;
    b -= t;
    result += t;

    t = m - b;
    b += t;
    c -= t;
    result += t;

    cout << result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}