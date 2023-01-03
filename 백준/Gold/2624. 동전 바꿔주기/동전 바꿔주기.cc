#include <iostream>

using namespace std;

int dp[10001] = {1};

void solution() {
    int T, K, p, n;

    cin >> T >> K;
    while (K--) {
        cin >> p >> n;
        for (int t = T; t >= p; t--)
            for (int i = 1; i <= n && p*i <= t; i++)
                dp[t] += dp[t-p*i];
    }
    cout << dp[T];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}