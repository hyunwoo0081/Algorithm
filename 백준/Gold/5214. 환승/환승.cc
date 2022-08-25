#include <iostream>
#include <queue>
#define SIZE 100'000
#define INF 987654321

using namespace std;

queue<pair<int, int>> q;
vector<int> cubes[1000];
vector<int> edges[SIZE];
int dist[SIZE];

void solution() {
    int N, K, M, a;
    int node, len;

    cin >> N >> K >> M;
    for (int i = 0; i < N; i++)
        dist[i] = INF;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> a;
            cubes[i].push_back(--a);
            edges[a].push_back(i);
        }
    }

    q.emplace(0, 1);
    dist[0] = 1;
    while (!q.empty()) {
        node = q.front().first;
        len = q.front().second;
        q.pop();

        if (node == N-1) break;

        for (auto edge: edges[node]) {
            for (auto next: cubes[edge]) {
                if (dist[next] == INF) {
                    q.emplace(next, len+1);
                    dist[next] = len+1;
                }
            }
        }
    }

    cout << (dist[N-1] == INF ? -1 : dist[N-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}