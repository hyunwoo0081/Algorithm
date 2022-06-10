#include <iostream>
#include <queue>

using namespace std;

bool map[50][50];
int visited[50][50];
queue<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int getLength(int sx, int sy, int N, int M) {
    int x, y, nx, ny, visit;
    for (y = 0; y < N; ++y)
        for (x = 0; x < M; ++x)
            visited[y][x] = 0;

    int maxNum = 0;
    visited[sy][sx] = 1;
    q.emplace(sx*50+sy, 1);
    while (!q.empty()) {
        x = q.front().first/50;
        y = q.front().first%50;
        visit = q.front().second;
        q.pop();

        if (visited[y][x] < visit) continue;

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < M && 0 <= ny && ny < N && map[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = visit+1;
                q.emplace(nx*50+ny, visit+1);
                maxNum = max(maxNum, visit);
            }
        }
    }

    return maxNum;
}

void solution() {
    int N, M;
    string s;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        cin >> s;
        for (int x = 0; x < M; ++x) {
            map[y][x] = s[x] == 'L';
        }
    }

    int maxNum = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (map[y][x])
                maxNum = max(maxNum, getLength(x, y, N, M));
        }
    }
    cout << maxNum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}