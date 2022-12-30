#include <iostream>

using namespace std;
typedef long long ll;

ll dp[64][10] = {0};

void solution() {
    int T, n;
    ll sum;

    for (int i = 0; i < 10; i++)
        dp[0][i] = 1;

    for (int k = 1; k < 64; k++) {
        dp[k][0] = dp[k-1][0];
        for (int i = 1; i < 10; i++)
            dp[k][i] = dp[k-1][i] + dp[k][i-1];
    }

    cin >> T;
    while (T--) {
        cin >> n;
        sum = 0;
        for (int i = 0; i < 10; i++)
            sum += dp[n - 1][i];
        cout << sum << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}