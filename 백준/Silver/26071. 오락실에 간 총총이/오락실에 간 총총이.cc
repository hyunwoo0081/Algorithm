#include <iostream>

using namespace std;

void solution() {
    int N, left, right, top, down, sameX, sameY;
    string s;

    left = right = top = down = sameX = sameY = -2;
    cin >> N;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < N; x++) {
            if (s[x] == '.') continue;

            left = max(left, x);
            right = max(right, N - x - 1);
            top = max(top, y);
            down = max(down, N - y - 1);

            if (sameX == -2) {
                sameX = x;
                sameY = y;
            }
            if (sameX != x) sameX = -1;
            if (sameY != y) sameY = -1;
        }
    }

    cout << (sameX < 0) * min(left, right) + (sameY < 0) * min(top, down) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}