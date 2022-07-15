#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

struct Vec2 {
    int x, y;
};

bool map[101][101] = {false};
int visited[101][101][3];
queue<pair<int, int>> q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int getMinLength(Vec2& move1, Vec2& move2, int N, int M) {
    int x, y, nx, ny, dist;
    while (!q.empty()) q.pop();

    for (y = 0; y < M; y++)
        for (x = 0; x < N; x++)
            for (int i = 0; i < 3; i++)
                visited[y][x][i] = -1;

    visited[move1.y][move1.x][2] = 0;
    q.emplace(move1.x*1000+move1.y, 0);
    while (!q.empty()) {
        x = q.front().first/1000;
        y = q.front().first%1000;
        dist = q.front().second;
        q.pop();

        if (visited[y][x][2] > dist) continue;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M
                    && !map[ny][nx] && visited[ny][nx][2] < 0) {
                visited[ny][nx][0] = x;
                visited[ny][nx][1] = y;
                visited[ny][nx][2] = dist+1;
                q.emplace(nx*1000+ny, dist+1);

                if (nx == move2.x && ny == move2.y)
                    return dist+1;
            }
        }
    }
    return INF;
}

void makeMap(Vec2 end) {
    int nx, ny;
    while (end.x >= 0) {
        map[end.y][end.x] = true;

        nx = visited[end.y][end.x][0];
        ny = visited[end.y][end.x][1];
        end.x = nx;
        end.y = ny;
    }
}

int getMinOnMaps(Vec2& fix1, Vec2& fix2, Vec2& move1, Vec2& move2, int N, int M) {
    int result;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            map[y][x] = false;

    map[move1.y][move1.x] = true;
    map[move2.y][move2.x] = true;
    result = getMinLength(fix1, fix2, N, M);
    makeMap(fix2);

    map[move1.y][move1.x] = false;
    map[move2.y][move2.x] = false;

    return min(INF, result + getMinLength(move1, move2, N, M));
}

void solution() {
    int N, M;
    Vec2 A1, A2, B1, B2;

    cin >> N >> M;
    N++, M++;
    cin >> A1.x >> A1.y;
    cin >> A2.x >> A2.y;
    cin >> B1.x >> B1.y;
    cin >> B2.x >> B2.y;

    int result = min(getMinOnMaps(A1, A2, B1, B2, N, M),
                     getMinOnMaps(B1, B2, A1, A2, N, M));

    if (result < INF)
        cout << result;
    else
        cout << "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}