#include <iostream>
#define SIZE 2000

using namespace std;

int dx[] = {-1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, -1, 0, 1};

int maps[SIZE][SIZE];
void dfs(int x, int y, int N) {
    int i, nx, ny;
    for (int i = 0; i < 7; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (maps[ny][nx] != 1) continue;

        maps[ny][nx] = 3;
        dfs(nx, ny, N);
    }
}

void solution() {
    int N, x, y, sx, sy;
    string s;
    cin >> N;

    for (y = 0; y < N; y++) {
        cin >> s;
        for (x = 0; x < N; x++) {
            maps[y][x] = s[x] == '.';

            if (s[x] == 'F') {
                sx = x;
                sy = y;
            }
        }
    }

    dfs(sx, sy, N);

    int result = 0;
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            result += maps[y][x] == 3;
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