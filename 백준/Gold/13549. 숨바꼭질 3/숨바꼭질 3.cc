#include <iostream>
#include <deque>
#define SIZE 100001

using namespace std;

deque<pair<int, int>> dq;
int dp[SIZE];

void solution() {
    int N, K, dist;

    cin >> N >> K;

    if (N >= K) {
        cout << N-K;
        return;
    }

    for (auto &init : dp)
        init = -1;

    dq.emplace_front(N, 0);
    dp[N] = 0;
    while (!dq.empty() && dq.front().first != K) {
        N = dq.front().first;
        dist = dq.front().second;
        dq.pop_front();

        if (0 <= dp[N] && dp[N] < dist)
            continue;
        dp[N] = dist;

        if (2*N < SIZE && dp[2*N] <= -1) {
            dq.emplace_front(2*N, dist);
            dp[2*N] = dist;
        }

        if (N+1 < SIZE && dp[N+1] == -1) {
            dq.emplace_back(N+1, dist+1);
            dp[N+1] = -2;
        }

        if (N-1 > 0 && dp[N-1] == -1) {
            dq.emplace_back(N-1, dist+1);
            dp[N-1] = -2;
        }
    }

    while (!dq.empty()) {
        N = dq.front().first;
        dist = dq.front().second;
        dq.pop_front();

        if (0 <= dp[N] && dp[N] < dist)
            continue;
        dp[N] = dist;
    }

    cout << dp[K];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}