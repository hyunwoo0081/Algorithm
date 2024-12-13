#include <iostream>
#define SIZE 3000
#define MOD 1'000'000'009

using namespace std;

long long dp[SIZE][SIZE];
char maps[SIZE][SIZE];
void solution() {
    int N, M, S, y, x;
    string s;

    cin >> N >> M;
    for (y = 0; y < N; y++) {
        cin >> s;
        for (x = 0; x < M; x++) {
            maps[y][x] = s[x];
        }
    }

    dp[N-1][M-1] = 1;
    for (S = N+M-3; S >= 0; S--) {
        for (y = 0; y < N; y++) {
            x = S - y;
            if (x < 0 || x >= M) continue;

            if (maps[y][x] == 'E')
                dp[y][x] = dp[y][x+1];
            else if (maps[y][x] == 'S')
                dp[y][x] = dp[y+1][x];
            else
                dp[y][x] = (dp[y+1][x] + dp[y][x+1]) % MOD;
        }
    }

    long long result = 0;
    for (y = 0; y < N; y++) {
        for (x = 0; x < M; x++) {
            result = (result + dp[y][x]) % MOD;
        }
    }

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}