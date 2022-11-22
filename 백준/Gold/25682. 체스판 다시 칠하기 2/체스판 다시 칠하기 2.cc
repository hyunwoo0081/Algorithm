#include <iostream>
#define SIZE 2000

using namespace std;

int dp[SIZE][SIZE][2] = {0};

int getCount(int x, int y, int k) {
    return x >= 0 && y >= 0 ? dp[y][x][k] : 0;
}

void solution() {
    int N, M, K;
    string s;

    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < M; x++) {
            for (int k = 0; k < 2; k++) {
                dp[y][x][k] = getCount(x-1, y, k) + getCount(x, y-1, k) - getCount(x-1, y-1, k)
                                + ((x+y+k) % 2 == (s[x] == 'B'));
            }
        }
    }

    int minColor = 987654321;
    for (int y = K-1; y < N; y++)
        for (int x = K-1; x < M; x++)
            for (int k = 0; k < 2; k++)
                minColor = min(minColor, getCount(x, y, k) - getCount(x-K, y, k) - getCount(x, y-K, k) + getCount(x-K, y-K, k));

    cout << minColor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}