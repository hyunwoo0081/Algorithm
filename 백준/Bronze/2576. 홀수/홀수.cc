#include <iostream>

using namespace std;

void solution() {
    int minX, sumX, a;

    minX = 321, sumX = 0;
    for (int i = 0; i < 7; i++) {
        cin >> a;
        if (a % 2) {
            minX = min(minX, a);
            sumX += a;
        }
    }

    if (sumX == 0)
        cout << -1;
    else
        cout << sumX << '\n' << minX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}