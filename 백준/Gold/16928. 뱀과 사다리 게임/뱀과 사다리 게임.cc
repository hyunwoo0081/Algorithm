#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

int nextM[100] = {0};
int dist[100];
queue<pair<int, int>> q;

void solution() {
    int N, M, x, y, d, nx;

    for (auto &a: dist)
        a = INF;

    cin >> N >> M;
    N = N+M;
    while (N--) {
        cin >> x >> y;
        x--, y--;
        nextM[x] = y;
    }

    q.emplace(0, 0);
    dist[0] = 0;
    while (!q.empty()) {
        x = q.front().first;
        d = q.front().second;
        q.pop();

        if (dist[x] < d) continue;
        if (x == 99) break;

        for (int i = 1; i <= 6; i++) {
            nx = x + i;
            if (nx < 100 && dist[nx] == INF) {
                if (nextM[nx] > 0) {
                    dist[nx] = d+1;
                    nx = nextM[nx];
                }
                if (dist[nx] == INF) {
                    dist[nx] = d+1;
                    q.emplace(nx, d+1);
                }
            }
        }
    }
    cout << dist[99];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}