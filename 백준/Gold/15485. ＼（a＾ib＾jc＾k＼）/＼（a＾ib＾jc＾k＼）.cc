#include <iostream>
#define SIZE 1'000'000
#define MOD 1'000'000'007

using namespace std;

long long dp[3][SIZE];

void solution() {
    bool isStart = false;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (!isStart && s[i] != 'a') continue;
        isStart = true;

        if (i > 0) {
            dp[0][i] = dp[0][i-1];
            dp[1][i] = dp[1][i-1];
            dp[2][i] = dp[2][i-1];
        }

        if (s[i] == 'a') {
            dp[0][i] = dp[0][i] ? dp[0][i]*2+1 : 1;
            dp[0][i] = dp[0][i] % MOD;
        }
        else if (s[i] == 'b') {
            dp[1][i] = dp[1][i]*2 + dp[0][i];
            dp[1][i] = dp[1][i] % MOD;
        }
        else {
            dp[2][i] = dp[2][i]*2 + dp[1][i];
            dp[2][i] = dp[2][i] % MOD;
        }
    }

    cout << dp[2][s.length()-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}