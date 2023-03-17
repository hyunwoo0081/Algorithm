#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> edges[10001];
int dist[10001];

void solution() {
    int M, N, a, b, c;

    cin >> N >> M;
    while (N--) {
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
    }

    for (int i = 1; i <= M; i++)
        dist[i] = 987654321;

    for (auto v : edges[0])
        dist[v.first] = min(dist[v.first], v.second);

    for (int i = 1; i <= M; i++) {
        dist[i] = min(dist[i], dist[i-1]+1);
        for (auto v : edges[i])
            dist[v.first] = min(dist[v.first], dist[i] + v.second);
    }

    cout << dist[M];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}