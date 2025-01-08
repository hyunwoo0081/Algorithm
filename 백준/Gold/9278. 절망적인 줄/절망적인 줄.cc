#include <iostream>
#define SIZE 501
#define MOD 1'000'000

using namespace std;

int dp[SIZE][SIZE];

void solution() {
    int x, y, len;
    string s;

    while (cin >> s) {
        fill(&dp[0][0], &dp[SIZE - 1][SIZE], 0);
        dp[0][0] = 1;

        len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '.' || s[i] == '(') {
                for (x = 0; x <= (i+1)/2; x++) {
                    y = i+1 - x;
                    if (y > len/2) continue;
                    dp[y][x] = (dp[y][x] + dp[y-1][x]) % MOD;
                }
            }

            if (s[i] == '.' || s[i] == ')') {
                for (x = 1; x <= (i+1)/2; x++) {
                    y = i+1 - x;
                    if (y > len/2) continue;
                    dp[y][x] = (dp[y][x] + dp[y][x-1]) % MOD;
                }
            }
        }

        cout << dp[len/2][len/2] << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}