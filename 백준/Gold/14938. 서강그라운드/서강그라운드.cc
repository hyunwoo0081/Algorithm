#include <iostream>
#define SIZE 100
#define INF 987654

using namespace std;

int items[SIZE];
int dist[SIZE][SIZE];

void solution() {
    int n, m, r, a, b, l, maxCount, count;

    cin >> n >> m >> r;

    // init dist array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = i == j ? 0 : INF;

    for (int i = 0; i < n; i++)
        cin >> items[i];

    while (r--) {
        cin >> a >> b >> l;
        a--, b--;

        dist[a][b] = l;
        dist[b][a] = l;
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    maxCount = 0;
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++)
            if (dist[i][j] <= m)
                count += items[j];
        maxCount = max(maxCount, count);
    }
    cout << maxCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
