#include <iostream>

using namespace std;

void solution() {
    int N, minX, minY, maxX, maxY, x, y;

    cin >> N >> x >> y;
    minX = maxX = x;
    minY = maxY = y;
    N--;
    while (N--) {
        cin >> x >> y;
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }

    cout << ((long long)maxX - minX) * (maxY - minY);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}