#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 100000000

using namespace std;

int dists[100][100];

void solution() {
    int N, M, x, y, cost;

    cin >> N >> M;
    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            dists[y][x] = INF;
        }
    }
    while (M--) {
        cin >> x >> y >> cost;
        x--, y--;
        dists[x][y] = min(cost, dists[x][y]);
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i != k && j != k && i != j) {
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }
    }


    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            cout << (dists[y][x] >= INF ? 0 : dists[y][x]) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}