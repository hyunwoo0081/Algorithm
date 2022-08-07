#include <iostream>
#include <queue>
#define SIZE 10000
#define INF 10'000'000'000

using namespace std;
typedef long long ll;

priority_queue<pair<ll, ll>> q;
vector<pair<int, int>> edges[SIZE];
ll dist[SIZE][21];

void solution() {
    int N, M, K, a, b, c;
    ll d, node, k, next, nextD;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (auto &dis: dist[i])
            dis = INF;

    while (M--) {
        cin >> a >> b >> c;
        a--, b--;
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }

    // dijkstra
    q.emplace(0, 0);
    dist[0][0] = 0;
    while (!q.empty()) {
        d = -q.top().first;
        node = q.top().second % SIZE;
        k = q.top().second / SIZE;
        q.pop();

        if (d > dist[node][k]) continue;

        for (auto edge: edges[node]) {
            next = edge.first;
            nextD = edge.second;
            if (d + nextD < dist[next][k]) {
                q.emplace(-(d + nextD), k*SIZE+next);
                dist[next][k] = d + nextD;
            }
            if (k < K && d < dist[next][k+1]) {
                q.emplace(-d, (k+1)*SIZE+next);
                dist[next][k+1] = d;
            }
        }
    }

    ll minDist = INF;
    for (int i = 0; i <= K; i++)
        minDist = min(minDist, dist[N-1][i]);
    cout << minDist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}