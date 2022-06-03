#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 10000

using namespace std;

int edges[16][16];
int dp[1<<16];
queue<pair<int, int>> q;

int getActiveCount(int x) {
    int count = 0;
    for (int i = 1; i < (1<<16); i<<=1) {
        if (x & i) count++;
    }
    return count;
}

void solution() {
    int N, P;
    string s;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> edges[i][j];
        }
    }
    cin >> s >> P;

    int node = 0;
    int activeCount = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'Y') {
            node |= (1 << i);
            activeCount++;
        }
    }
    for (int &item : dp) item = INF;

    if (activeCount == 0) {
        if (P == 0) cout << 0;
        else cout << -1;
        return;
    }

    int value, minValue = -1;
    dp[node] = 0;
    q.emplace(node, 0);
    while (!q.empty()) {
        node = q.front().first;
        value = q.front().second;
        q.pop();

        if (dp[node] < value) continue;
        if (getActiveCount(node) >= P && (minValue == -1 || minValue > dp[node])) {
            minValue = dp[node];
            continue;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if ((node & (1<<i)) && !(node & (1<<j)) && dp[node]+edges[i][j] < dp[node|(1<<j)]) {
                    int next = node|(1<<j);
                    dp[next] = dp[node]+edges[i][j];
                    q.emplace(next, dp[next]);
                }
            }
        }
    }

    cout << minValue;
}

int main() {
    fastIO();
    solution();

    return 0;
}