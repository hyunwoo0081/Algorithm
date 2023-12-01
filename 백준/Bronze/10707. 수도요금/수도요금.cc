#include <iostream>

using namespace std;

void solution() {
    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;

    cout << min(a*p, b + max(0, p-c) * d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}