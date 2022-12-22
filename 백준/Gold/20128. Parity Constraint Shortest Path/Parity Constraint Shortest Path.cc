#include <iostream>
#include <queue>
#define SIZE 100000
#define INF 100'000'000'000'001

using namespace std;
typedef long long ll;

vector<pair<int, int>> edges[SIZE];
priority_queue<pair<ll, int>> pq;
ll dist[SIZE][2];

void solution() {
    int N, M, u, v, w;
    ll d, nd;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        dist[i][0] = dist[i][1] = INF;

    while (M--) {
        cin >> u >> v >> w;
        u--, v--;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }

    dist[0][0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        v = pq.top().second;
        d = -pq.top().first;
        pq.pop();

        if (d > dist[v][d%2])
            continue;

        for (auto e : edges[v]) {
            u = e.first;
            nd = (ll) d + e.second;
            if (nd < dist[u][nd%2]) {
                dist[u][nd%2] = nd;
                pq.emplace(-nd, u);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j >= 0; j--) {
            cout << (dist[i][j] == INF ? -1 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}