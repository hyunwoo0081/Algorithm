#include <iostream>

using namespace std;

long long dp[2][21] = {0};

void solution() {
    int N, a;

    cin >> N >> a;
    dp[0][a] = 1;
    for (int i = 1; i < N-1; i++) {
        cin >> a;
        for (int k = 0; k < 21; k++) {
            dp[i%2][k] = 0;
            if (k >= a)
                dp[i%2][k] += dp[(i+1)%2][k-a];
            if (k <= 20-a)
                dp[i%2][k] += dp[(i+1)%2][k+a];
        }
    }

    cin >> a;
    cout << dp[(N-2)%2][a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}