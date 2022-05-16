#include <iostream>
#include <deque>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 100001

using namespace std;

deque<int> dq;
int dp[SIZE];

void solution() {
    int N, K;

    cin >> N >> K;

    if (N >= K) {
        cout << N-K;
        return;
    }

    for (auto &init : dp)
        init = -1;

    dq.push_front(N);
    dp[N] = 0;
    while (dq.front() != K) {
        N = dq.front();
        dq.pop_front();

        if (2*N < SIZE && dp[2*N] == -1) {
            dq.push_front(2*N);
            dp[2*N] = dp[N];
        }

        if (N+1 < SIZE && dp[N+1] == -1) {
            dq.push_back(N+1);
            dp[N+1] = dp[N]+1;
        }

        if (N-1 > 0 && dp[N-1] == -1) {
            dq.push_back(N-1);
            dp[N-1] = dp[N]+1;
        }
    }
    cout << dp[K];
}

int main() {
    fastIO();
    solution();

    return 0;
}