#include <iostream>

using namespace std;

int maps[8][2] = {
        {1, 2},
        {-1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, 1},
        {-2, -1},
};

void solution() {
    int T, n, r1, c1, r2, c2, x, y;
    bool flag = false;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        flag = false;
        cin >> n >> r1 >> c1 >> r2 >> c2;

        for (auto ds : maps) {
            x = r1 + ds[0];
            y = c1 + ds[1];
            if (r2 == x && c2 == y)
                flag = true;
        }

        cout << "Case " << t << ": " << (flag ? "YES\n" : "NO\n");
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}