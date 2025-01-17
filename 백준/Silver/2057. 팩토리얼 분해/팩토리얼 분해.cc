#include <iostream>
#define SIZE 20

using namespace std;

long long dp[SIZE] = {1};

bool canMake(long long N, int p) {
    bool result = false;
    if (N == 0)
        return true;
    if (p >= SIZE)
        return false;

    for (int i = p; i < SIZE && N >= dp[i]; i++) {
        result |= canMake(N - dp[i], i+1);
    }

    return result;
}

void solution() {
    long long N;

    dp[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        dp[i] = dp[i-1]*i;
    }

    cin >> N;
    cout << (N != 0 && canMake(N, 0) ? "YES" : "NO");
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}