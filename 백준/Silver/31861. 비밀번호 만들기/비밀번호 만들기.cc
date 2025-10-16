#include <iostream>
#define ALPHA 26
#define MOD 1'000'000'007

using namespace std;

long long dp[2][ALPHA];
int main() {
    int N, M;
    long long sum;
    
    cin >> N >> M;
    for (int i = 0; i < ALPHA; i++) {
        dp[1][i] = 1;
    }
    
    for (int m = 2; m <= M; m++) {
        auto prev = dp[(m+1)%2];
        auto &now = dp[m%2];
        for (int i = 0; i < ALPHA; i++) {
            now[i] = 0;
            for (int j = 0; j < ALPHA; j++) {
                if (i-N < j && j < i+N) continue;
                now[i] = (now[i] + prev[j]) % MOD;
            }
        }
    }
    
    sum = 0;
    for (int i = 0; i < ALPHA; i++) {
        sum = (sum + dp[M%2][i]) % MOD;
    }
    cout << sum;

    return 0;
}