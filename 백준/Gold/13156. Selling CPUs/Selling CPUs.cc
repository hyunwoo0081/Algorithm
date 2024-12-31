#include <iostream>
#define SIZE 101

using namespace std;


int dp[SIZE] = {0};
int arr[SIZE];
void solution() {
    int C, M;

    cin >> C >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[j];
        }

        if (i == 0) {
            for (int j = 1; j <= C; j++) {
                dp[j] = arr[j-1];
            }
        } else {
            for (int j = C; j > 0; j--) {
                for (int k = 1; k <= j; k++) {
                    dp[j] = max(dp[j], dp[j-k] + arr[k-1]);
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= C; i++) {
        result = max(result, dp[i]);
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}