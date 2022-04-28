#include <iostream>
#include <functional>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char map[100][100];
bool visited[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool compare(int x, int y, int nx, int ny) {
    return map[y][x] == map[ny][nx];
}

bool compareRG(int x, int y, int nx, int ny) {
    return compare(x, y, nx, ny) || map[y][x] != 'B' && map[ny][nx] != 'B';
}

void bfs(int x, int y, int N, function<bool(int, int, int, int)> &func) {
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[ny][nx] && func(x, y, nx, ny))
            bfs(nx, ny, N, func);
    }
}

int getAreaCount(int N, function<bool(int, int, int, int)> func) {
    int count = 0;

    for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
            visited[y][x] = false;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (!visited[y][x]) {
                bfs(x, y, N, func);
                count++;
            }
        }
    }

    return count;
}

void solution() {
    int N;

    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];
        }
    }

    cout << getAreaCount(N, compare) << ' ';
    cout << getAreaCount(N, compareRG);
}

int main() {
    fastIO();
    solution();

    return 0;
}