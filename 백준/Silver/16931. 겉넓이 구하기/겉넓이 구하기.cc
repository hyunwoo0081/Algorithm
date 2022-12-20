#include <iostream>

using namespace std;

int map[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solution() {
    int n, m, nx, ny, area;

    cin >> n >> m;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            cin >> map[y][x];

    area = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            area += 2 + 4*map[y][x];
            for (int i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                if (0 <= nx && nx < m && 0 <= ny && ny < n)
                    area -= min(map[y][x], map[ny][nx]);
            }
        }
    }
    cout << area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}