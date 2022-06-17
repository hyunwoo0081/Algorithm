#include <iostream>
#define SIZE 2000

using namespace std;

int inputs[SIZE];
bool dp[SIZE][SIZE] = {false};

void solution() {
    int N, M, S, E;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> inputs[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; 0 <= i-j && i+j < N && inputs[i-j] == inputs[i+j]; ++j) {
            dp[i-j][i+j] = true;
        }

        for (int j = 0; 0 <= i-j && i+1+j < N && inputs[i-j] == inputs[i+1+j]; ++j) {
            dp[i-j][i+1+j] = true;
        }
    }

    cin >> M;
    while (M--) {
        cin >> S >> E;
        cout << dp[S-1][E-1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}