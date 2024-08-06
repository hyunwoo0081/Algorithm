#include <iostream>

using namespace std;

void solution() {
    int w, h, d;

    cin >> w >> h >> d;

    w = max(0, w - 2 * d);
    h = max(0, h - 2 * d);

    cout << w * h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}