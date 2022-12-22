#include <iostream>
#define SIZE 100

using namespace std;

char map[SIZE][SIZE];
char tmpMap[SIZE][SIZE];
int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

void solution() {
    int R, C, px, py, count, minI, minV, nx, ny;
    string s;

    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        cin >> s;
        for (int x = 0; x < C; x++) {
            map[y][x] = s[x];
            if (s[x] == 'I')
                px = x, py = y;
        }
    }

    cin >> s;
    count = 1;
    for (auto cmd : s) {
        map[py][px] = '.';
        px += dx[cmd-'1'];
        py += dy[cmd-'1'];
        if (map[py][px] == 'R') {
            cout << "kraj " << count;
            return;
        }
        map[py][px] = 'I';

        // move Rs
        for (int y = 0; y < R; y++)
            for (int x = 0; x < C; x++)
                tmpMap[y][x] = '.';

        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (map[y][x] != 'R')
                    continue;

                minI = -1;
                minV = 987654321;
                for (int i = 0; i < 9; i++) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if (0 <= nx && nx < C && 0 <= ny && ny < R &&
                        abs(px-nx) + abs(py-ny) < minV) {
                        minI = i;
                        minV = abs(px-nx) + abs(py-ny);
                    }
                }

                nx = x + dx[minI];
                ny = y + dy[minI];
                tmpMap[ny][nx] = tmpMap[ny][nx] == '.' ? 'R' : '#';
            }
        }

        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++){
                if (map[y][x] == 'I') {
                    if (tmpMap[y][x] != '.') {
                        cout << "kraj " << count;
                        return;
                    }
                }
                else
                    map[y][x] = tmpMap[y][x] == 'R' ? 'R' : '.';
            }
        }
        count++;
    }

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++)
            cout << map[y][x];
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}