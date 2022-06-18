#include <iostream>
#include <queue>
#define EMPTY '.'
#define DOOR '#'
#define WALL '*'
#define MIRROR '!'

using namespace std;

char map[50][50];
int visited[2][50][50];
deque<pair<int, int>> q;
int startX, startY, endX, endY;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solution() {
    int N, x, y, dir, nx, ny;
    string s;

    cin >> N;
    startX = -1;
    for (y = 0; y < N; ++y) {
        cin >> s;
        for (x = 0; x < N; ++x) {
            map[y][x] = s[x];
            visited[0][y][x] = visited[1][y][x] = -1;

            if (s[x] == DOOR) {
                map[y][x] = EMPTY;
                if (startX == -1)
                    startX = x, startY = y;
                else
                    endX = x, endY = y;
            }
        }
    }

    // 0-1 bfs
    visited[0][startY][startX] = 0;
    visited[1][startY][startX] = 0;
    for (dir = 0; dir < 4; ++dir) {
        nx = startX + dx[dir];
        ny = startY + dy[dir];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && map[ny][nx] != WALL) {
            visited[dir%2][ny][nx] = 0;
            q.emplace_back(nx*100+ny, dir);

            if (map[ny][nx] == MIRROR) {
                visited[!(dir%2)][ny][nx] = 1;
                q.emplace_back(nx*100+ny, (dir+1)%4);
                q.emplace_back(nx*100+ny, (dir+3)%4);
            }
        }
    }

    while (!q.empty()) {
        x = q.front().first/100;
        y = q.front().first%100;
        dir = q.front().second;
        q.pop_front();

        if (endX == x && endY == y) break;

        nx = x + dx[dir];
        ny = y + dy[dir];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[dir % 2][ny][nx] < 0 && map[ny][nx] != WALL) {
            visited[dir % 2][ny][nx] = visited[dir % 2][y][x];
            q.emplace_front(nx*100+ny, dir);

            if (map[ny][nx] == MIRROR) {
                visited[!(dir%2)][ny][nx] = visited[dir%2][y][x] + 1;
                q.emplace_back(nx*100+ny, (dir+1)%4);
                q.emplace_back(nx*100+ny, (dir+3)%4);
            }
        }
    }

    cout << max(visited[0][endY][endX], visited[1][endY][endX]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}