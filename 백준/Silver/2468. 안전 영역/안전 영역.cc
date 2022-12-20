#include <iostream>

using namespace std;

int map[100][100];
bool visited[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int N, int threshold) {
    int nx, ny;

    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && map[ny][nx] > threshold && !visited[ny][nx])
            dfs(nx, ny, N, threshold);
    }
}

int getAreaCount(int N, int threshold) {
    int count = 0;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            visited[y][x] = false;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] > threshold && !visited[y][x]) {
                count++;
                dfs(x, y, N, threshold);
            }
        }
    }
    return count;
}

void solution() {
    int N, maxH = 0, maxCount = 1;

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            maxH = max(maxH, map[y][x]);
        }
    }

    for (int i = 0; i <= maxH; i++)
        maxCount = max(maxCount, getAreaCount(N, i));

    cout << maxCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}