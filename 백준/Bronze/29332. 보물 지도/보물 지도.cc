#include <iostream>

using namespace std;

void solution() {
    long long N, x, y, minX, maxX, minY, maxY;
    bool L, R, U, D;
    char c;
    L = R = U = D = false;
    minX = minY = -9876543210L;
    maxX = maxY = 9876543210L;

    cin >> N;
    while (N--) {
        cin >> x >> y >> c;

        if (c == 'L')
            L = true, maxX = min(maxX, x);
        else if (c == 'R')
            R = true, minX = max(minX, x);
        else if (c == 'U')
            U = true, minY = max(minY, y);
        else if (c == 'D')
            D = true, maxY = min(maxY, y);
    }

    if (L && R && U && D)
        cout << (maxX - minX - 1) * (maxY - minY - 1);
    else
        cout << "Infinity";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}