#include <iostream>

using namespace std;

void solution() {
    int a;

    cin >> a;
    cout << fixed;
    cout.precision(2);
    cout << (double) a / 4.;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}