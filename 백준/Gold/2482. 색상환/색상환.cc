#include <iostream>
#define MOD 1'000'000'003

using namespace std;

int dp[1000][1000] = {0};

long long getDp(int n, int k) {
    return n < 0 || k < 0 ? 0 : dp[n][k];
}

void calcDp(int N, int K) {
    for (int k = 1; k < K; ++k) {
        for (int n = 1; n < N; ++n) {
            dp[n][k] = (int) (getDp(n-1, k) + getDp(n-2, k-1)) % MOD;
        }
    }
}

void solution() {
    int N, K;
    cin >> N >> K;

    for (int n = 0; n < N; ++n)
        dp[n][0] = 1;
    calcDp(N, K);

    long long count = 0;
    for (int n = 0; n < N; ++n) {
        count = (count + dp[n][K-1]) % MOD;
    }

    for (int n = 0; n < N; ++n)
        dp[n][0] = 0;
    dp[0][0] = 1;
    calcDp(N, K);

    count = (MOD + count - dp[N-1][K-1]) % MOD;
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}