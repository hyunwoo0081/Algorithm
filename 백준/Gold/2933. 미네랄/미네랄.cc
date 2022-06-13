#include <iostream>
#define MINERAL 'x'
#define EMPTY '.'

using namespace std;

char map[100][100];
bool visited[100][100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int R, int C) {
    int nx, ny;
    for (int i = 0; i < 4; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < C && 0 <= ny && ny < R && !visited[ny][nx] && map[ny][nx] == MINERAL) {
            visited[ny][nx] = true;
            dfs(nx, ny, R, C);
        }
    }
}

void fallCluster(int R, int C) {
    int minLength = R-1;
    int fy;

    for (int x = 0; x < C; ++x) {
        fy = -1;
        for (int y = 0; y < R; ++y) {
            if (map[y][x] == EMPTY) continue;

            if (visited[y][x]) {
                fy = y;
            }
            else {
                minLength = min(minLength, y-fy-1);
                break;
            }
        }
    }

    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (map[y][x] == MINERAL && !visited[y][x]) {
                map[y-minLength][x] = MINERAL;
                map[y][x] = EMPTY;
            }
        }
    }
}

void solution() {
    int R, C, N, cx, cy;
    string s;

    cin >> R >> C;
    for (int y = R-1; y >= 0; --y) {
        cin >> s;
        for (int x = 0; x < C; ++x) {
            map[y][x] = s[x];
        }
    }

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> cy;
        cy--;
        if (i%2 == 0) {
            for (cx = 0; cx < C && map[cy][cx] == EMPTY; ++cx);
            if (cx >= C) continue;
        }
        else {
            for (cx = C-1; cx >= 0 && map[cy][cx] == EMPTY; --cx);
            if (cx < 0) continue;
        }
        map[cy][cx] = EMPTY;

        for (int y = 0; y < R; ++y)
            for (int x = 0; x < C; ++x)
                visited[y][x] = false;
        for (int x = 0; x < C; ++x)
            if(!visited[0][x] && map[0][x] == MINERAL)
                dfs(x, 0, R, C);

        int nx, ny;
        for (int j = 0; j < 4; ++j) {
            nx = cx + dx[j];
            ny = cy + dy[j];
            if (0 <= nx && nx < C && 0 <= ny && ny < R && !visited[ny][nx] && map[ny][nx] == MINERAL) {
                fallCluster(R, C);
                break;
            }
        }
    }

    for (int y = R-1; y >= 0; --y) {
        for (int x = 0; x < C; ++x) {
            cout << map[y][x];
        }
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