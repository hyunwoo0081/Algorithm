#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 1000
#define INF 1000000000

using namespace std;

int map[SIZE][SIZE];
int dp[SIZE][SIZE][2];

void solution() {
    int N, M;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> map[y][x];
            dp[y][x][0] = dp[y][x][1] = -INF;
        }
    }

    dp[0][0][0] = map[0][0];
    for (int x = 1; x < M; ++x) {
        dp[0][x][0] = map[0][x] + dp[0][x-1][0];
    }

    for (int y = 1; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            dp[y][x][0] = map[y][x] + max(dp[y-1][x][0], dp[y-1][x][1]);
            if (x > 0)
                dp[y][x][0] = max(dp[y][x][0], dp[y][x-1][0] + map[y][x]);
        }

        for (int x = M-1; x >= 0; --x) {
            dp[y][x][1] = map[y][x] + max(dp[y-1][x][0], dp[y-1][x][1]);
            if (x < M-1)
                dp[y][x][1] = max(dp[y][x][1], dp[y][x+1][1] + map[y][x]);
        }
    }

    cout << max(dp[N-1][M-1][0], dp[N-1][M-1][1]);
}

int main() {
    fastIO();
    solution();

    return 0;
}