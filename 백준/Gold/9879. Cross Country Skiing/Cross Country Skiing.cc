#include <iostream>
#include <queue>
#define SIZE 500

using namespace std;


int maps[SIZE][SIZE];
int points[SIZE][SIZE];
bool visited[SIZE][SIZE];
queue<pair<int, int>> q;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int bfs(int sx, int sy, int M, int N, int D) {
    int result = 0;
    for (auto & y : visited)
        for (bool & x : y)
            x = false;

    visited[sy][sx] = true;
    q.emplace(sx, sy);
    result += points[sy][sx];
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[ny][nx] || abs(maps[y][x] - maps[ny][nx]) > D) continue;

            visited[ny][nx] = true;
            q.emplace(nx, ny);

            result += points[ny][nx];
        }
    }

    return result;
}

void solution() {
    int M, N, D, minN, maxN;
    int sx=0, sy=0, pointCount = 0;

    cin >> M >> N;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cin >> maps[y][x];

            if (y == 0 && x == 0) {
                minN = maxN = maps[y][x];
                continue;
            }
            minN = min(minN, maps[y][x]);
            maxN = max(maxN, maps[y][x]);
        }
    }

    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cin >> D;
            points[y][x] = D == 1;

            if (points[y][x]) {
                sx = x;
                sy = y;
                pointCount++;
            }
        }
    }

    int left = 0, right = maxN - minN;
    while (left < right) {
        int mid = (left + right) / 2;
        bool isPossible = bfs(sx, sy, M, N, mid) == pointCount;

        if (isPossible) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    D = left;
    cout << D;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}