#include <iostream>
#define MOD 1'000'000'007

using namespace std;

long long dp[3] = {0};

void solution() {
    bool isStart = false;
    string s;
    cin >> s;

    for (char c : s) {
        if (!isStart && c != 'a') continue;
        isStart = true;

        if (c == 'a')
            dp[0] = dp[0] ? (dp[0]*2 + 1) % MOD : 1;
        else if (c == 'b')
            dp[1] = (dp[1]*2 + dp[0]) % MOD;
        else
            dp[2] = (dp[2]*2 + dp[1]) % MOD;
    }

    cout << dp[2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}