#include <iostream>

using namespace std;

char map[8][8][8];

bool dfs(int x, int y, int depth) {
    int nx, ny;
    if (depth >= 8) return true;
    if (map[y][x][depth] != '.') return false;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            nx = x + dx;
            ny = y + dy;
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && map[ny][nx][depth] == '.') {
                if (dfs(nx, ny, depth+1))
                    return true;
            }
        }
    }

    return false;
}

void solution() {
    int x, y;
    string s;

    for (y = 0; y < 8; ++y) {
        cin >> s;
        for (x = 0; x < 8; ++x) {
            for (int c = 0; c < 8; ++c) {
                if (y+c < 8)
                    map[y+c][x][c] = s[x];
            }
        }
    }

    for (int c = 1; c < 8; ++c) {
        for (y = 0; y < c; y++) {
            for (x = 0; x < 8; ++x) {
                map[y][x][c] = '.';
            }
        }
    }

    cout << dfs(0, 7, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}