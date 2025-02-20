#include <iostream>
#include <queue>
#define SIZE 20

using namespace std;

bool maps[SIZE][SIZE];
int visited[SIZE][SIZE];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<pair<int, int>> q;

void solution() {
    int N, M, result = 987654321;
    string s;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < M; x++)
            maps[y][x] = s[x] == '1';
    }

    for (int sy = 0; sy < N; sy++) {
        for (int sx = 0; sx < M; sx++) {
            for (int ssy = 0; ssy < N; ssy++) {
                for (int ssx = 0; ssx < M; ssx++) {
                    if (sy == ssy && sx == ssx || maps[sy][sx] || maps[ssy][ssx]) continue;

                    for (int y = 0; y < N; y++)
                        for (int x = 0; x < M; x++)
                            visited[y][x] = 0;

                    q.emplace(sx, sy);
                    visited[sy][sx] = 1;
                    q.emplace(ssx, ssy);
                    visited[ssy][ssx] = 1;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];

                            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                            if (visited[ny][nx]) continue;

                            q.emplace(nx, ny);
                            visited[ny][nx] = visited[y][x] + 1;
                        }
                    }

                    int cnt = 0;
                    for (int y = 0; y < N; y++)
                        for (int x = 0; x < M; x++)
                            if (maps[y][x])
                                cnt = max(cnt, visited[y][x]);

                    result = min(result, cnt-1);
                }
            }
        }
    }

    cout << result << '\n';
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}