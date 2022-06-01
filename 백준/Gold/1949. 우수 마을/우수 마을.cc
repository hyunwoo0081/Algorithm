#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 10000

using namespace std;

int dp[2][SIZE] = {0};
vector<int> edges[SIZE];
int people[SIZE];

int dfs(int node, int prevNode) {
    dp[1][node] = people[node];

    if (prevNode >= 0 && edges[node].size() == 1)
        return dp[1][node];

    for (int next: edges[node]) {
        if (next == prevNode) continue;
        dfs(next, node);

        dp[1][node] += dp[0][next];
        dp[0][node] += max(dp[0][next], dp[1][next]);
    }

    return max(dp[0][node], dp[1][node]);
}

void solution() {
    int N, a, b;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> people[i];
    }
    for (int i = 0; i < N-1; ++i) {
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    cout << dfs(0, -1) << '\n';
}

int main() {
    fastIO();
    solution();

    return 0;
}