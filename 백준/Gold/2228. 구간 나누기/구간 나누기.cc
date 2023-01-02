#include <iostream>
#define INF 987654321

using namespace std;

int prefix[100];
int dp[100][51];

int getSum(int s, int e) {
    return s > 0 ? prefix[e]-prefix[s-1] : prefix[e];
}

int getMax(int s, int e, int m) {
    if (m < 0) return 0;
    if (dp[s][m] != INF) return dp[s][m];

    int &cache = dp[s][m] = -INF;
    for (int i = s; i <= e-2*m; ++i) {
        for (int j = i; j <= e-2*m; ++j) {
            int next = getMax(j+2, e, m-1);
            if (next != -INF)
                cache = max(cache, getSum(i, j) + next);
        }
    }
    return cache;
}

void solution() {
    int N, M;

    cin >> N >> M >> prefix[0];
    for (int i = 1; i < N; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dp[i][j] = INF;

    cout << getMax(0, N-1, M-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}