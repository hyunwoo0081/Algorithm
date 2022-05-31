#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define MOD 1'000'000'000

using namespace std;

int dp[2][10][1<<10] = {0};

void solution() {
    int N;
    cin >> N;

    if(N < 10) {
        cout << 0;
        return;
    }

    for (int i = 1; i < 10; ++i)
        dp[1][i][1<<i] = 1;

    for (int i = 2; i <= N; ++i) {
        int k = i%2;
        for (int lastNum = 0; lastNum < 10; ++lastNum) {
            for (int visit = 1; visit < (1 << 10); ++visit) {
                if (lastNum > 0) {
                    int &memo = dp[k][lastNum-1][visit | (1 << (lastNum-1))];
                     memo = (memo + dp[!k][lastNum][visit]) % MOD;
                }
                if (lastNum < 9) {
                    int &memo = dp[k][lastNum+1][visit | (1 << (lastNum+1))];
                    memo =  (memo + dp[!k][lastNum][visit]) % MOD;
                }
            }
        }

        for (int lastNum = 0; lastNum < 10; ++lastNum) {
            for (int visit = 1; visit < (1 << 10); ++visit) {
                dp[!k][lastNum][visit] = 0;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum = (sum + dp[N%2][i][(1<<10)-1]) % MOD;
    }
    cout << sum;
}

int main() {
    fastIO();
    solution();

    return 0;
}