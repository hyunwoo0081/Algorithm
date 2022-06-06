#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int map[100][100];
long long dp[100][100] = {0};

void solution() {
    int N;
    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];
        }
    }

    dp[0][0] = 1;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (map[y][x] == 0) continue;

            if (x + map[y][x] < N) {
                dp[y][x+map[y][x]] += dp[y][x];
            }
            if (y + map[y][x] < N) {
                dp[y+map[y][x]][x] += dp[y][x];
            }
        }
    }

    cout << dp[N-1][N-1];
}

int main() {
    fastIO();
    solution();

    return 0;
}