#include <iostream>

using namespace std;

void solution() {
    int w, h;

    cin >> w >> h;

    cout.precision(1);
    cout << fixed;
    cout << w * h / 2.;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}