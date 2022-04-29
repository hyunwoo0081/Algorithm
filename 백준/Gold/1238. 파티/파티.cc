#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 10000000

using namespace std;

vector<pair<int, int>> edge[1000];
priority_queue<pair<int, int>> q;
int dijkstraDist[1000];
int length[1000] = {0};

void dijkstra(int start, int end, int N) {
    int dist, node, nextNode, nextDist;

    for (int i = 0; i < N; ++i)
        dijkstraDist[i] = INF;
    while (!q.empty())
        q.pop();

    dijkstraDist[start] = 0;
    q.emplace(0, start);
    while (!q.empty()) {
        dist = -q.top().first;
        node = q.top().second;
        q.pop();

        if (dist > dijkstraDist[node]) continue;
        if (node == end) return;

        for (auto next: edge[node]) {
            nextNode = next.first;
            nextDist = dist + next.second;
            if (nextDist < dijkstraDist[nextNode]) {
                dijkstraDist[nextNode] = nextDist;
                q.emplace(-nextDist, nextNode);
            }
        }
    }
}

void solution() {
    int N, M, X, a, b, T;

    cin >> N >> M >> X;
    X--;
    while (M--) {
        cin >> a >> b >> T;
        edge[a-1].emplace_back(b-1, T);
    }

    dijkstra(X, -1, N);
    for (int i = 0; i < N; ++i)
        length[i] = dijkstraDist[i];

    for (int i = 0; i < N; ++i) {
        dijkstra(i, X, N);
        length[i] += dijkstraDist[X];
    }

    int maxLength = 0;
    for (int i = 0; i < N; ++i) {
        maxLength = max(maxLength, length[i]);
    }
    cout << maxLength;
}

int main() {
    fastIO();
    solution();

    return 0;
}