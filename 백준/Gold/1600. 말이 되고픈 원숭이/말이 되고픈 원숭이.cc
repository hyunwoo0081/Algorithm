#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

bool map[200][200];
int dist[200][200][31] = {0};
queue<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ddx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ddy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void solution() {
    int K, W, H;
    int x, y, d, k, nx, ny;

    cin >> K >> W >> H;
    for (y = 0; y < H; y++) {
        for (x = 0; x < W; x++) {
            cin >> d;
            map[y][x] = !d;
            for (k = 0; k <= K; k++)
                dist[y][x][k] = INF;
        }
    }

    q.emplace(0, 0);
    dist[0][0][0] = 0;
    while (!q.empty()) {
        x = q.front().first / 200;
        y = q.front().first % 200;
        d = q.front().second / 100;
        k = q.front().second % 100;
        q.pop();

        if (d > dist[y][x][k]) continue;
        if (x == W-1 && y == H-1) break;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H
                    && map[ny][nx] && dist[ny][nx][k] == INF) {
                q.emplace(nx*200+ny, (d+1)*100 + k);
                dist[ny][nx][k] = d+1;
            }
        }

        if (k >= K) continue;
        for (int i = 0; i < 8; i++) {
            nx = x + ddx[i];
            ny = y + ddy[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H
                && map[ny][nx] && dist[ny][nx][k+1] == INF) {
                q.emplace(nx*200+ny, (d+1)*100 + k+1);
                dist[ny][nx][k+1] = d+1;
            }
        }
    }

    d = INF;
    for (k = 0; k <= K; k++)
        d = min(d, dist[H-1][W-1][k]);

    cout << (d == INF ? -1 : d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}