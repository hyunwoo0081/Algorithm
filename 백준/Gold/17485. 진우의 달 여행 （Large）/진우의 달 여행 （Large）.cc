#include <iostream>
#define SIZE 1000
#define INF 987654321

using namespace std;

int dp[2][3][SIZE];
int dx[] = {-1, 0, 1};

void solution() {
    int N, M, cost, nx;

    cin >> N >> M;
    for (int x = 0; x < M; x++) {
        cin >> cost;
        for (int i = 0; i < 3; i++)
            dp[0][i][x] = cost;
    }

    for (int y = 1; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> cost;
            for (int i = 0; i < 3; i++) {
                dp[y%2][i][x] = INF;
                for (int j = 0; j < 3; j++) {
                    nx = x + dx[j];
                    if (i != j && 0 <= nx && nx < M)
                        dp[y%2][i][x] = min(dp[y%2][i][x], dp[(y-1)%2][j][nx]);
                }
                dp[y%2][i][x] += cost;
            }
        }
    }

    cost = INF;
    for (int x = 0; x < M; x++)
        for (int i = 0; i < 3; i++)
            cost = min(cost, dp[(N-1)%2][i][x]);
    cout << cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}