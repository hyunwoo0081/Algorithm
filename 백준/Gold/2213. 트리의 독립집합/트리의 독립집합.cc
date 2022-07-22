#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int w[10000];
int dp[10000][2] = {0};
bool visited[10000] = {false};
vector<int> edges[10000];
vector<int> list;

bool getW(int node) {
    if (dp[node][0] >= 0) return false;

    dp[node][true] = w[node];
    dp[node][false] = 0;
    for (auto next: edges[node]) {
        if(!getW(next)) continue;
        dp[node][true] += dp[next][false];
        dp[node][false] += max(dp[next][true], dp[next][false]);
    }
    return true;
}

void assignList(int node, bool jump) {
    if (visited[node]) return;
    visited[node] = true;

    if(!jump && dp[node][true] > dp[node][false])
        list.push_back(node);

    for (auto next: edges[node]) {
        if (!jump && dp[node][true] > dp[node][false])
            assignList(next, true);
        else
            assignList(next, false);
    }
}

void printList(int node) {
    assignList(node, false);
    sort(list.begin(), list.end());

    for (auto l : list)
        cout << l+1 << ' ';
}

void solution() {
    int N, x, y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
        dp[i][false] = -1;
    }
    while (cin >> x >> y) {
        x--, y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    getW(0);

    cout << max(dp[0][true], dp[0][false]) << '\n';
    printList(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}