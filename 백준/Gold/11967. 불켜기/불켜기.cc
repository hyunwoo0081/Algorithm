#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define OFF 0
#define ON 1
#define VISIT 2

using namespace std;

int visited[100][100] = {2};
vector<pair<int, int>> edges[100][100];
queue<pair<int, int>> q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool canReach(int x, int y, int N) {
    int nx, ny;
    for (int i = 0; i < 4; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[ny][nx] == VISIT)
            return true;
    }
    return false;
}

//void searchOn(int x, int y, int N) {
//    visited[y][x] = VISIT;
//
//    int nx, ny;
//    for (auto next: edges[y][x]) {
//        nx = next.first;
//        ny = next.second;
//        if (visited[ny][nx] == OFF) {
//            visited[ny][nx] = ON;
//            q.emplace(nx, ny);
//        }
//    }
//
//    for (int i = 0; i < 4; ++i) {
//        nx = x + dx[i];
//        ny = y + dy[i];
//        if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[ny][nx] == ON) {
//            searchOn(nx, ny, N);
//        }
//    }
//}

void solution() {
    int N, M, x, y, a, b;
    cin >> N >> M;
    while (M--) {
        cin >> x >> y >> a >> b;
        edges[y-1][x-1].emplace_back(a-1, b-1);
    }

    int nx, ny;

    visited[0][0] = VISIT;
    for (auto next: edges[0][0]) {
        nx = next.first;
        ny = next.second;
        visited[ny][nx] = ON;
        q.emplace(nx, ny);
    }

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (visited[y][x] == VISIT || !canReach(x, y, N)) continue;

        visited[y][x] = VISIT;
        for (auto next: edges[y][x]) {
            nx = next.first;
            ny = next.second;
            if (visited[ny][nx] == OFF) {
                q.emplace(nx, ny);
                visited[ny][nx] = ON;
            }
        }

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[ny][nx] == ON) {
                q.emplace(nx, ny);
            }
        }
    }


    int count = 0;
    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            if (visited[y][x] > 0)
                count++;
        }
    }
    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}