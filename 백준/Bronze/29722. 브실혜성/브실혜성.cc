#include <iostream>

using namespace std;

void solution() {
    int y, m, d, plus;
    char c;

    cin >> y >> c >> m >> c >> d >> plus;
    d += plus;
    if (d > 30) {
        d -= 1;
        m += d / 30;
        d = d % 30 + 1;
    }
    if (m > 12) {
        m -= 1;
        y += m / 12;
        m = m % 12 + 1;
    }

    cout << y << '-' << (m < 10 ? "0" : "") << m << '-' << (d < 10 ? "0" : "") << d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}