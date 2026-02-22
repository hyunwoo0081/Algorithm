#include <iostream>
#define SIZE 15

using namespace std;

int dp[SIZE][SIZE] = {1};

int main() {
    int N, M, K;
    
    cin >> N >> M >> K;
    
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (y > 0) dp[y][x] += dp[y-1][x];
            if (x > 0) dp[y][x] += dp[y][x-1];
        }
    }
    
    if (K == 0) {
        cout << dp[N-1][M-1];
    }
    else {
        int y = K / M;
        int x = K % M - 1;
        
        cout << dp[y][x] * dp[N-1-y][M-1-x];
    }

    return 0;
}