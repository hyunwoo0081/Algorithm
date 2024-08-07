#include <iostream>

using namespace std;

void solution() {
    int N, minX, maxX, minY, maxY, x, y, l;

    cin >> N >> x >> y;
    minX = maxX = x;
    minY = maxY = y;
    N--;

    while (N--) {
        cin >> x >> y;

        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    l = maxX - minX;
    if (maxY - minY > l)
        l = maxY - minY;

    cout << l * l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}