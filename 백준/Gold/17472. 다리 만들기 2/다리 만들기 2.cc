#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 1000

using namespace std;

int map[10][10];
int edges[6][6];
bool visited[6] = {false};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void markingMap(int x, int y, int N, int M, int num) {
    int nx, ny;
    map[y][x] = num;
    for (int i = 0; i < 4; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && map[ny][nx] == -2) {
            markingMap(nx, ny, N, M, num);
        }
    }
}

void solution() {
    int N, M;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> map[y][x];
            map[y][x] = -map[y][x]-1;
        }
    }
    for (auto &e:edges)
        for (auto &edge: e)
            edge = INF;

    //marking map
    int mapCount = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (map[y][x] == -2) {
                markingMap(x, y, N, M, mapCount++);
            }
        }
    }

    //find edges
    int continent, length;
    for (int y = 0; y < N; ++y) {
        length = 0;
        continent = -1;
        for (int x = 0; x < M; ++x) {
            if (map[y][x] >= 0) {
                if (continent >= 0 && continent != map[y][x] && length > 1) {
                    edges[continent][map[y][x]] = edges[map[y][x]][continent] = min(length, edges[map[y][x]][continent]);
                }
                continent = map[y][x];
                length = 0;
            }
            else {
                length++;
            }
        }
    }
    for (int x = 0; x < M; ++x) {
        length = 0;
        continent = -1;
        for (int y = 0; y < N; ++y) {
            if (map[y][x] >= 0) {
                if (continent >= 0 && continent != map[y][x] && length > 1) {
                    edges[continent][map[y][x]] = edges[map[y][x]][continent] = min(length, edges[map[y][x]][continent]);
                }
                continent = map[y][x];
                length = 0;
            }
            else {
                length++;
            }
        }
    }

    //prim
    int minA, minB;
    int sum = 0, count = 0;
    visited[0] = true;
    while (count < mapCount-1) {
        minA = minB = 0; //edges[minA][minB] == INF
        for (int j = 0; j < mapCount; ++j) {
            if (!visited[j]) continue;
            for (int k = 0; k < mapCount; ++k) {
                if (!visited[k] && edges[j][k] < edges[minA][minB]) {
                    minA = j;
                    minB = k;
                }
            }
        }
        if (edges[minA][minB] == INF) {
            sum = -1;
            break;
        }
        visited[minA] = visited[minB] = true;
        sum += edges[minA][minB];
        count++;
    }

    cout << sum;
}

int main() {
    fastIO();
    solution();

    return 0;
}