#include <iostream>

using namespace std;

// dp[i][j] -> j=0: prev 선택 x now 선택 x, j=1: prev 선택 o now 선택 x, j=2: prev 선택 x now 선택 o, j=3: prev 선택 o now 선택 o
// arr[i][j] -> j = 선택된 이웃의 개수
long long dp[2][4];
int arr[2][3];

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int now = i % 2;
        int prev = (i + 1) % 2;

        for (auto &j : arr[now]) {
            cin >> j;
        }

        if (i == 0) {
            dp[0][0] = dp[0][1] = 0;
            dp[0][2] = dp[0][2] = arr[0][0];
            continue;
        }
        if (i == 1) {
            dp[1][0] = 0;
            dp[1][1] = arr[0][0];
            dp[1][2] = arr[1][0];
            dp[1][3] = arr[0][1] + arr[1][1];
            continue;
        }

        dp[now][0] = max(dp[prev][0], dp[prev][1]);
        dp[now][1] = max(dp[prev][2], dp[prev][3]);
        dp[now][2] = max(dp[prev][0], dp[prev][1]) + arr[now][0];
        dp[now][3] = max(dp[prev][2]-arr[prev][0]+arr[prev][1], dp[prev][3]-arr[prev][1]+arr[prev][2]) + arr[now][1];
    }

    int now = (N - 1) % 2;
    long long result = 0;
    for (int i = 0; i < 4; i++) {
        result = max(result, dp[now][i]);
    }

    cout << result << '\n';
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}