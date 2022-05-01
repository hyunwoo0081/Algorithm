#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define EMPTY -1

using namespace std;

int map[500][500];
int dp[500][500];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int dfs(int x, int y, int N, int depth) {
    if (dp[y][x] > 0) return dp[y][x];

    int nx, ny, maxCount;

    maxCount = 1;
    for (int i = 0; i < 4; ++i) {
        nx = x+dx[i];
        ny = y+dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && map[ny][nx] > map[y][x]) {
            maxCount = max(maxCount, dfs(nx, ny, N, depth+1) + 1);
        }
    }

    return dp[y][x] = maxCount;
}

void solution() {
    int n;

    cin >> n;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            cin >> map[y][x];
            dp[y][x] = EMPTY;
        }
    }

    int maxCount = 0;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            maxCount = max(maxCount, dfs(x, y, n, 0));
        }
    }

    cout << maxCount;
}

int main() {
    fastIO();
    solution();

    return 0;
}