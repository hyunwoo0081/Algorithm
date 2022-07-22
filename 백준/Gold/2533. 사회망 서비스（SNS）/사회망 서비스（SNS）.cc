#include <iostream>
#include <vector>
#define SIZE 1'000'000

using namespace std;

int dp[SIZE][2] = {0};
vector<int> edges[SIZE];

bool calc(int node) {
    if (dp[node][true])
        return false;

    dp[node][false] = 0;
    dp[node][true] = 1;
    for (auto next : edges[node]) {
        if (!calc(next)) continue;

        dp[node][true] += min(dp[next][true], dp[next][false]);
        dp[node][false] += dp[next][true];
    }
    return true;
}

void solution() {
    int N, a, b;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    calc(0);

    cout << min(dp[0][0], dp[0][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}