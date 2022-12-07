#include <iostream>

using namespace std;

void solution() {
    double minW;
    int x, y, m;

    cin >> x >> y >> m;
    minW = (double) x / y;
    while (m--) {
        cin >> x >> y;
        minW = min(minW, (double) x / y);
    }
    cout << minW * 1000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}