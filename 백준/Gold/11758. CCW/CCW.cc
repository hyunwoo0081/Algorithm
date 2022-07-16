#include <iostream>

using namespace std;

void solution() {
    int x1, y1, x2, y2, x3, y3, f;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    x1 = x1-x2;
    y1 = y1-y2;
    x3 = x3-x2;
    y3 = y3-y2;

    f = x3*y1 - x1*y3;
    cout << (f == 0 ? 0 : f/abs(f));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}