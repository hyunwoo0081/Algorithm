#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100'000

using namespace std;

vector<int> edges[SIZE];
int dist[SIZE];
int visitedCount = 0;

void dfs(int start) {
    dist[start] = ++visitedCount;

    for (auto next: edges[start])
        if (!dist[next])
            dfs(next);
}

void solution() {
    int N, M, R, u, v;

    cin >> N >> M >> R;
    while (M--) {
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 0; i < N; i++)
        sort(edges[i].begin(), edges[i].end());

    dfs(--R);

    for (int i = 0; i < N; i++)
        cout << dist[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}