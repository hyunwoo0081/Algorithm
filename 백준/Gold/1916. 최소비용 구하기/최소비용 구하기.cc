#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 1'000'000'000

using namespace std;

vector<pair<int, int>> edges[1000];
priority_queue<pair<long long, int>> q;
long long dist[1000] = {0};

long long getMin(int A, int B, int N) {
    int node, nextNode;
    long long cost, nextCost;

    for (int i = 0; i < N; ++i)
        dist[i] = INF;

    dist[A] = 0;
    q.emplace(0, A);
    while (!q.empty()) {
        cost = -q.top().first;
        node = q.top().second;
        q.pop();

        if (cost > dist[node]) continue;
        if (node == B) return dist[B];

        for (auto edge: edges[node]) {
            nextNode = edge.first;
            nextCost = dist[node] + edge.second;

            if (nextCost < dist[nextNode]) {
                q.emplace(-nextCost, nextNode);
                dist[nextNode] = nextCost;
            }
        }
    }

    return -1;
}

void solution() {
    int N, M, A, B, Cost;

    cin >> N >> M;
    while (M--) {
        cin >> A >> B >> Cost;
        edges[A-1].emplace_back(B-1, Cost);
    }
    cin >> A >> B;

    cout << getMin(A-1, B-1, N);
}

int main() {
    fastIO();
    solution();

    return 0;
}