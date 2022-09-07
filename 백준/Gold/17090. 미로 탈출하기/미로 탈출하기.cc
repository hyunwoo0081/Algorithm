#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
char map[500][500];
bool visited[500][500] = {false};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char pos[] = {'L', 'D', 'R', 'U'};

void printMap(int N, int M) {
    int x, y;
    for (y = 0; y < N; y++) {
        for (x = 0; x < M; x++)
            cout << visited[y][x];
        cout << '\n';
    }
    cout << '\n';
}

void solution() {
    int N, M, x, y, nx, ny;
    string s;

    cin >> N >> M;
    for (y = 0; y < N; y++) {
        cin >> s;
        for (x = 0; x < M; x++)
            map[y][x] = s[x];
    }

    //push possible position
    for (y = 0; y < N; y++) {
        if (map[y][0] == 'L') {
            q.emplace(0, y);
            visited[y][0] = true;
        }
        if (map[y][M-1] == 'R') {
            q.emplace(M-1, y);
            visited[y][M-1] = true;
        }
    }
    for (x = 0; x < M; x++) {
        if (map[0][x] == 'U') {
            q.emplace(x, 0);
            visited[0][x] = true;
        }
        if (map[N-1][x] == 'D') {
            q.emplace(x, N-1);
            visited[N-1][x] = true;
        }
    }

    // BFS
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < M && 0 <= ny && ny < N
                && !visited[ny][nx] && map[ny][nx] == pos[i]) {
                q.emplace(nx, ny);
                visited[ny][nx] = true;
            }
        }
    }

    int count = 0;
    for (y = 0; y < N; y++)
        for (x = 0; x < M; x++)
            count += visited[y][x];
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}