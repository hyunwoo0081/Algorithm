#include <iostream>
#define SIZE 2000
#define INF 987654321

using namespace std;

int dp[SIZE][21];
int arr[SIZE];

int upper(int a) {
    if (a % 10 < 5)
        return a / 10 * 10;
    return a / 10 * 10 + 10;
}

void solution() {
    int N, D;

    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= D; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = arr[0];
    dp[0][1] = upper(arr[0]);
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i-1][0] + arr[i];
        for (int j = 1; j <= D; j++) {
            dp[i][j] = min(dp[i-1][j] + arr[i], upper(dp[i][j-1]));
        }
    }

    int result = upper(dp[N-1][0]);
    for (int i = 1; i <= D; i++) {
        result = min(result, upper(dp[N-1][i]));
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