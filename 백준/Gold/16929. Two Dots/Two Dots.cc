#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char map[50][50];
bool visited[50][50] = {false};
bool isLoop[50][50] = {false};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool hasCycle(int x, int y, int N, int M, int prevDir) {
    if (isLoop[y][x]) return true;
    if (visited[y][x]) return false;

    visited[y][x] = true;
    isLoop[y][x] = true;

    int nx, ny;
    for (int i = 0; i < 4; ++i) {
        if (prevDir == (i+2)%4) continue;

        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && map[y][x] == map[ny][nx]) {
            if (hasCycle(nx, ny, N, M, i))
                return true;
        }
    }
    isLoop[y][x] = false;
    return false;
}

void solution() {
    int N, M;
    string s;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        cin >> s;
        for (int x = 0; x < M; ++x) {
            map[y][x] = s[x];
        }
    }

    bool cycle = false;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (!visited[y][x] && hasCycle(x, y, N, M, -1)) {
                cycle = true;
                break;
            }
        }
    }

    cout << (cycle ? "Yes" : "No");
}

int main() {
    fastIO();
    solution();

    return 0;
}