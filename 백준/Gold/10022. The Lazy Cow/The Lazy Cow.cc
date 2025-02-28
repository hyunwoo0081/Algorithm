#include <iostream>
#define SIZE 400

using namespace std;

int maps[SIZE][SIZE];
long long dp[SIZE][SIZE] = {0};

int getM(int x, int y, int N) {
    if (y < 0 || x < 0 || y >= N || x >= N)
        return 0;
    return maps[y][x];
}

long long moveRight(int X, int Y, int N, int K) {
    int dx, dy;

    long long result = 0;
    for (dy = -K; dy <= K; dy++) {
        dx = abs(dy) - K - 1;
        result -= getM(X+dx, Y+dy, N);
    }

    for (dy = -K; dy <= K; dy++) {
        dx = K - abs(dy);
        result += getM(X+dx, Y+dy, N);
    }

    return result;
}

long long moveDown(int X, int Y, int N, int K) {
    int dx, dy;

    long long result = 0;
    for (dx = -K; dx <= K; dx++) {
        dy = abs(dx) - K - 1;
        result -= getM(X+dx, Y+dy, N);
    }

    for (dx = -K; dx <= K; dx++) {
        dy = K - abs(dx);
        result += getM(X+dx, Y+dy, N);
    }

    return result;
}

void solution() {
    int N, K, x, y;

    cin >> N >> K;
    for (y = 0; y < N; y++)
        for (x = 0; x < N; x++)
            cin >> maps[y][x];

    dp[0][0] = 0;
    for (y = 0; y <= K; y++)
        for (x = 0; x <= K-y; x++)
            dp[0][0] += getM(x, y, N);

    long long result = dp[0][0];
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            if (x == 0 && y == 0)
                continue;

            if (x == 0)
                dp[y][x] = dp[y-1][x] + moveDown(x, y, N, K);
            else
                dp[y][x] = dp[y][x-1] + moveRight(x, y, N, K);

            result = max(result, dp[y][x]);
        }
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}