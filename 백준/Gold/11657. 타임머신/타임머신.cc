#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 100000000

using namespace std;

typedef struct e {
    int from, to, weight;
} Edge;

vector<Edge> edges;
long long dist[501];

bool bellmanFord(int N) {
    const int startNode = 1;
    for (int i = 1; i <= N; ++i)
        dist[i] = INF;

    dist[startNode] = 0;

    for (int i = 1; i <= N; ++i) {
        for (Edge edge : edges) {
            if (dist[edge.to] > dist[edge.from] + edge.weight && dist[edge.from] != INF) {
                dist[edge.to] = dist[edge.from] + edge.weight;
                if (i == N) return true;
            }
        }
    }
    return false;
}

void solution() {
    int N, M;
    Edge e;

    cin >> N >> M;
    while (M--) {
        cin >> e.from >> e.to >> e.weight;
        edges.push_back(e);
    }

    bool hasNegCycle = bellmanFord(N);

    if(hasNegCycle)
        cout << -1;
    else {
        for (int i = 2; i <= N; ++i)
            cout << (dist[i] >= INF ? -1 : dist[i]) << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}