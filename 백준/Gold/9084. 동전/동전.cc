#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int dp[10001];
vector<int> coins;

int get(int x) {
    return x >= 0 ? dp[x] : 0;
}

void solution() {
    int T, N, coin, M;

    cin >> T;
    while (T--) {
        cin >> N;
        coins.clear();
        for (int i = 0; i < N; ++i) {
            cin >> coin;
            coins.push_back(coin);
        }
        cin >> M;

        // dp
        for (int i = 1; i <= M; ++i)
            dp[i] = i%coins[0] == 0;

        dp[0] = 1;
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j <= M; ++j) {
                dp[j] = get(j) + get(j-coins[i]);
            }
        }

        cout << get(M) << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}