#include <iostream>
#define MOD 1'000'000'009
#define SIZE 100'000

using namespace std;

int dp[SIZE + 10] = {0, 1, 2, 4, };
int notDiv[4] = {0, 1, 2, 2};

int getDp(int i) {
    if (i < 0) return 0;
    return dp[i];
}

int main() {
    int T, N;
    
    for (int i = 4; i <= SIZE; i++) {
        dp[i] = ((long long) dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
    
    cin >> T;
    while (T--) {
        cin >> N;
        
        int result = 0;
        int n2 = N/2;
        if (N < 4) {
            result = notDiv[N];
        }
        else {
            result = ((long long) getDp(n2) + getDp(n2-1)) % MOD;
        }
        
        cout << result << '\n';
    }
    
    return 0;
}