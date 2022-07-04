#include <iostream>
#include <queue>
#define SIZE 1000

using namespace std;

bool map[SIZE][SIZE];
bool visited[11][SIZE][SIZE] = {false};
queue<pair<int, int>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solution() {
    int N, M, K;
    int x, y, k, nx, ny, dist, result = -1;
    string s;
    
    cin >> N >> M >> K;
    for (y = 0; y < N; ++y) {
        cin >> s;
        for (x = 0; x < M; ++x) {
            map[y][x] = s[x] == '1';
        }
    }

    visited[0][0][0] = true;
    q.emplace(0, 100);
    while (!q.empty()) {
        x = q.front().first/SIZE;
        y = q.front().first%SIZE;
        k = q.front().second%100;
        dist = q.front().second/100;
        q.pop();

        if (x == M-1 && y == N-1) {
            result = dist;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                if (!map[ny][nx] && !visited[k][ny][nx]) {
                    visited[k][ny][nx] = true;
                    q.emplace(nx*SIZE+ny, (dist + 1)*100 + k);
                }
                else if (map[ny][nx] && k < K && !visited[k+1][ny][nx]) {
                    visited[k+1][ny][nx] = true;
                    q.emplace(nx*SIZE+ny, (dist + 1)*100 + k+1);
                }
            }
        }
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}