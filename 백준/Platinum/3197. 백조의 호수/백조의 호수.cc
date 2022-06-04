#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 1500

using namespace std;

char map[SIZE][SIZE];
bool visited[SIZE][SIZE] = {false};
queue<int> q[2];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool maskLake(int x, int y, int R, int C, char masking) {
    map[y][x] = masking;

    int nx, ny;
    for (int i = 0; i < 4; ++i) {
        nx = x+dx[i];
        ny = y+dy[i];
        if (0 <= nx && nx < C && 0 <= ny && ny < R && map[ny][nx] != 'X' && map[ny][nx] != masking) {
            if (map[ny][nx] == '.') {
                if (maskLake(nx, ny, R, C, masking)) return true;
            }
            else return true;
        }
    }

    return false;
}

void solution() {
    int R, C, nx, ny;
    string s;

    char L = 'A';
    int pos[2];
    cin >> R >> C;
    for (int y = 0; y < R; ++y) {
        cin >> s;
        for (int x = 0; x < C; ++x) {
            map[y][x] = s[x];
            // 백조 찾기
            if (s[x] == 'L') {
                map[y][x] = L;
                pos[L-'A'] = x*SIZE+y;
                L++;
            }
        }
    }

    //얼음 찾기
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (map[y][x] != 'X') {
                visited[y][x] = true;
                continue;
            }

            for (int i = 0; i < 4; ++i) {
                nx = x+dx[i];
                ny = y+dy[i];
                if (0 <= nx && nx < C && 0 <= ny && ny < R && map[ny][nx] != 'X' && !visited[y][x]) {
                    q[1].push(x*SIZE+y);
                    visited[y][x] = true;
                    break;
                }
            }
        }
    }

    bool isFinished = false;
    if (pos[0] >= 0) isFinished |= maskLake(pos[0]/SIZE, pos[0]%SIZE, R, C, 'A');
    if (pos[1] >= 0) isFinished |= maskLake(pos[1]/SIZE, pos[1]%SIZE, R, C, 'B');

    if (isFinished) {
        cout << 0;
        return;
    }

    int time = 0;
    while (!isFinished) {
        ++time;

        int x, y;
        while (!q[time%2].empty()) {
            x = q[time%2].front()/SIZE;
            y = q[time%2].front()%SIZE;
            q[time%2].pop();
            map[y][x] = '.';

            for (int i = 0; i < 4; ++i) {
                nx = x+dx[i];
                ny = y+dy[i];
                if (0 <= nx && nx < C && 0 <= ny && ny < R) {
                    if (map[ny][nx] == 'X' && !visited[ny][nx]) {
                        q[(time+1)%2].push(nx*SIZE+ny);
                        visited[ny][nx] = true;
                    }
                    else if (map[ny][nx] == 'A' || map[ny][nx] == 'B') {
                        if (maskLake(x, y, R, C, map[ny][nx]))
                            isFinished = true;
                    }
                }
            }
        }
    }

    cout << time;
}

int main() {
    fastIO();
    solution();

    return 0;
}