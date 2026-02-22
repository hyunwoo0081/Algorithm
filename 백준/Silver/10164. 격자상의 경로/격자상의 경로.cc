#include <iostream>
#define SIZE 15

using namespace std;

long long dp[SIZE][SIZE] = {1};

int main() {
    int N, M, K;
    
    cin >> N >> M >> K;
    
    int Y = (K-1) / M;
    int X = (K-1) % M;
    
    if (K == 0) {
        Y = N-1;
        X = M-1;
    }
    
    for (int y = 0; y <= Y; y++) {
        for (int x = 0; x <= X; x++) {
            if (y > 0) dp[y][x] += dp[y-1][x];
            if (x > 0) dp[y][x] += dp[y][x-1];
        }
    }
    
    for (int y = Y; y < N; y++) {
        for (int x = X; x < M; x++) {
            if (y > Y) dp[y][x] += dp[y-1][x];
            if (x > X) dp[y][x] += dp[y][x-1];
        }
    }
    
    cout << dp[N-1][M-1];

    return 0;
}