#include <iostream>
#include <queue>
#define EMPTY '.'
#define WALL '*'
#define RAZER 'C'

using namespace std;

struct Photon {
    int x, y, dir, count;
    Photon(int x, int y, int dir, int count) : x(x), y(y), dir(dir), count(count) {};
};

char map[100][100];
int visited[4][100][100];
deque<Photon> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solution() {
    int W, H, px, py;
    string s;

    cin >> W >> H;
    px = -1;
    for (int y = 0; y < H; ++y) {
        cin >> s;
        for (int x = 0; x < W; ++x) {
            map[y][x] = s[x];
            for (int i = 0; i < 4; ++i)
                visited[i][y][x] = -1;

            if (map[y][x] == RAZER && px == -1) {
                px = x, py = y;
                map[y][x] = EMPTY;
            }
        }
    }

    int x, y, dir, count, nx, ny;
    for (int i = 0; i < 4; ++i) {
        nx = px+dx[i];
        ny = py+dy[i];
        if (0 <= nx && nx < W && 0 <= ny && ny < H && map[ny][nx] != WALL) {
            q.emplace_front(nx, ny, i, 0);
            q.emplace_back(nx, ny, (i+1)%4, 1);
            q.emplace_back(nx, ny, (i+3)%4, 1);
            visited[i][ny][nx] = 0;
            visited[(i+1)%4][ny][nx] = 1;
            visited[(i+3)%4][ny][nx] = 1;
        }
        visited[i][py][px] = 0;
    }
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        dir = q.front().dir;
        count = q.front().count;
        q.pop_front();

        if (visited[dir][y][x] < count) continue;
        visited[dir][y][x] = count;

        if (map[y][x] == RAZER) {
            int num = 100000;
            for (int i = 0; i < 4; ++i)
                if (visited[i][y][x] >= 0)
                    num = min(num, visited[i][y][x]);
            cout << num;
            break;
        }

        for (int ndir = 0; ndir < 4; ++ndir) {
            if (ndir == (dir+2)%4) continue;
            nx = x + dx[ndir];
            ny = y + dy[ndir];
            if (0 <= nx && nx < W && 0 <= ny && ny < H && visited[ndir][ny][nx] == -1 || visited[ndir][ny][nx] > count) {
                if (map[ny][nx] == WALL) continue;

                if (ndir == dir) {
                    q.emplace_front(nx, ny, ndir, count);
                    visited[ndir][ny][nx] = count;
                }
                else {
                    q.emplace_back(nx, ny, ndir, count+1);
                    visited[ndir][ny][nx] = count+1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}