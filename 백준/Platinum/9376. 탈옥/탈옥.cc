#include <iostream>
#include <queue>
#define WALL '*'
#define EMPTY '.'
#define DOOR '#'
#define PERSON '$'

using namespace std;

char map[102][102];
int doorCount[102][102];
bool visited[102][102];
deque<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void addDoorCount(int startY, int startX, int H, int W) {
    int x, y, nx, ny, count;
    q.clear();
    for (y = 0; y < H+2; ++y)
        for (x = 0; x < W+2; ++x)
            visited[y][x] = false;

    q.emplace_front(startX*1000+startY, 0);
    visited[startY][startX] = true;

    while (!q.empty()) {
        x = q.front().first/1000;
        y = q.front().first%1000;
        count = q.front().second;
        q.pop_front();

        doorCount[y][x] = doorCount[y][x] < 0 ? count : doorCount[y][x]+count;

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < W+2 && 0 <= ny && ny < H+2
                    && !visited[ny][nx] && map[ny][nx] != WALL) {
                if (map[ny][nx] == DOOR) {
                    q.emplace_back(nx*1000+ny, count+1);
                    visited[ny][nx] = true;
                }
                else {
                    q.emplace_front(nx*1000+ny, count);
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

void solution() {
    int Tc, H, W;
    int p1X, p1Y, p2X, p2Y;
    string s;

    cin >> Tc;
    while (Tc--) {
        cin >> H >> W;
        p1X = -1;
        for (int y = 1; y <= H; ++y) {
            cin >> s;
            for (int x = 1; x <= W; ++x) {
                map[y][x] = s[x - 1];
                doorCount[y][x] = -1;

                if (s[x-1] == PERSON) {
                    if (p1X == -1)
                        p1X = x, p1Y = y;
                    else
                        p2X = x, p2Y = y;
                }
            }
            map[y][0] = map[y][W + 1] = EMPTY;
            doorCount[y][0] = doorCount[y][W + 1] = -1;
        }
        for (int x = 0; x < W+2; ++x) {
            map[0][x] = map[H + 1][x] = EMPTY;
            doorCount[0][x] = doorCount[H+1][x] = -1;
        }


        addDoorCount(0, 0, H, W);
        addDoorCount(p1Y, p1X, H, W);
        addDoorCount(p2Y, p2X, H, W);

        int minLength = 1000000000;
        for (int y = 0; y < H+2; ++y) {
            for (int x = 0; x < W+2; ++x) {
                if (doorCount[y][x] < 0) continue;
                minLength = min(minLength, doorCount[y][x] - 2*(map[y][x]==DOOR));
            }
        }

        cout << minLength << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}