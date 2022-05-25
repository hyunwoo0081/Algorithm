#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 1000

using namespace std;

int candy[SIZE][SIZE];
int dp[SIZE][SIZE] = {0};

void solution() {
    int N, M;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> candy[y][x];
        }
    }

    int count;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            count = 0;
            if (0 < x)
                count = dp[y][x-1];
            if (0 < y && dp[y-1][x] > count)
                count = dp[y-1][x];
            dp[y][x] = count + candy[y][x];
        }
    }

    cout << dp[N-1][M-1];
}

int main() {
    fastIO();
    solution();

    return 0;
}