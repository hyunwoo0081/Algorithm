#include <iostream>
#include <unordered_map>

using namespace std;

char block[] = {'.', '|', '-', '+', '1', '2', '3', '4'};
unordered_map<char, int> block2Int;
int map[25][25];
bool blockDir[8][4] = {{false, false, false, false},
                       {false, true, false, true},
                       {true, false, true, false},
                       {true, true, true, true},
                       {true, true, false, false},
                       {true, false, false, true},
                       {false, false, true, true},
                       {false, true, true, false}};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solution() {
    int R, C, mx, my, zx, zy, Ex, Ey, nx, ny, kinds;
    string s;

    for (int i = 0; i < 8; ++i)
        block2Int[block[i]] = i;
    block2Int['X'] = 0;
    block2Int['Z'] = 0;

    cin >> R >> C;
    for (int y = 0; y < R; ++y) {
        cin >> s;
        for (int x = 0; x < C; ++x) {
            map[y][x] = block2Int[s[x]];
            if (s[x] == 'M')
                mx = x, my = y;
            else if (s[x] == 'Z')
                zx = x, zy = y;
        }
    }


    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (map[y][x] || x == mx && y == my || x == zx && y == zy)
                continue;

            for (int i = 0; i < 4; ++i) {
                nx = x+dx[i];
                ny = y+dy[i];
                if (0 <= nx && nx < C && 0 <= ny && ny < R
                    && blockDir[map[ny][nx]][(i+2)%4]) {
                    Ex = x, Ey = y;
                    break;
                }
            }
        }
    }

    bool dirs[4];
    for (int i = 0; i < 4; ++i) {
        nx = Ex+dx[i];
        ny = Ey+dy[i];
        dirs[i] = (0 <= nx && nx < C && 0 <= ny && ny < R
                    && blockDir[map[ny][nx]][(i+2)%4]);
    }

    for (kinds = 1; kinds < 8; ++kinds) {
        int i;
        for (i = 0; i < 4 && blockDir[kinds][i] == dirs[i]; ++i);
        if (i == 4) break;
    }

    cout << Ey+1 << ' ' << Ex+1 << ' ' << block[kinds];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}