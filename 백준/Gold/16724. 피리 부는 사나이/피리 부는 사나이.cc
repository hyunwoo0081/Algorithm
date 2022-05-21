#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define EMPTY '\0'

using namespace std;

char map[1000][1000];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char trigger[] ={'U', 'L', 'D', 'R'};

int getDir(char dir) {
    switch (dir) {
        case 'U': return 2;
        case 'L': return 3;
        case 'D': return 0;
        case 'R': return 1;
        default: return -1;
    }
}

void dfs(int x, int y, int N, int M) {
    int nx, ny;
    int dir = getDir(map[y][x]);
    map[y][x] = EMPTY;
    for (int i = 0; i < 4; ++i) {
        nx = x+dx[i];
        ny = y+dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && (map[ny][nx] == trigger[i] || i == dir)) {
            dfs(nx, ny, N, M);
        }
    }
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

    int count = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (map[y][x] != EMPTY) {
                count++;
                dfs(x, y, N, M);
            }
        }
    }
    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}