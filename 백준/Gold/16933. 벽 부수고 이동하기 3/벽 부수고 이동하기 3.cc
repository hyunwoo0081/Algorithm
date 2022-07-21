#include <iostream>
#include <queue>
#define SIZE 1000

using namespace std;

queue<pair<int, int>> q;
bool map[SIZE][SIZE];
int visited[SIZE][SIZE][11] = {0};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int getLength(int N, int M, int K) {
    int x, y, k, d, nx, ny;
    bool isFirst;

    visited[0][0][0] = 1;
    q.emplace(0, 1);
    while (!q.empty()) {
        x = q.front().first/2000/20;
        y = q.front().first/20 % 2000;
        k = q.front().first % 20;
        d = abs(q.front().second);
        isFirst = q.front().second >= 0;
        q.pop();

        if (d - !isFirst > visited[y][x][k]) continue;
        if (x == M-1 && y == N-1) return d;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                if (!map[ny][nx] && !visited[ny][nx][k]) {
                    visited[ny][nx][k] = d+1;
                    q.emplace(nx*2000*20 + ny*20 + k, d+1);
                }
                else if (map[ny][nx] && !visited[ny][nx][k+1] && k+1 <= K && d%2) {
                    visited[ny][nx][k+1] = d+1;
                    q.emplace(nx*2000*20 + ny*20 + k+1, d+1);
                }
            }
        }

        if (isFirst) {
            q.emplace(x*2000*20 + ny*20 + k, -(d+1));
        }
    }

    return -1;
}

void solution() {
    int N, M, K;
    string s;

    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < M; x++) {
            map[y][x] = s[x] == '1';
        }
    }

    cout << getLength(N, M, K);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}