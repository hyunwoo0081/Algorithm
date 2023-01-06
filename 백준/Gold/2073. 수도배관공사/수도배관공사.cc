#include <iostream>
#define SIZE 100'001

using namespace std;

int dp[SIZE] = {987654321};

void solution() {
    int D, P, L, C;

    cin >> D >> P;
    while (P--) {
        cin >> L >> C;
        for (int i = D; i >= L; i--)
            if (dp[i-L] != 0 && dp[i] < min(C, dp[i-L]))
                dp[i] = min(C, dp[i-L]);
    }
    cout << dp[D];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}