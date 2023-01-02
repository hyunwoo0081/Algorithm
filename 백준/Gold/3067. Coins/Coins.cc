#include <iostream>
#define SIZE 10001

using namespace std;

int dp[SIZE];
int coins[20];

void solution() {
    int T, N, M;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        cin >> M;

        for (int j = 0; j <= M; j++)
            dp[j] = j % coins[0] == 0;

        for (int i = 1; i < N; i++)
            for (int j = coins[i]; j <= M; j++)
                dp[j] += dp[j-coins[i]];

        cout << dp[M] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}