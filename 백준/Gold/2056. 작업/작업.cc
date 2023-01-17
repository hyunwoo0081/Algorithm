#include <iostream>
#include <queue>
#define SIZE 10000

using namespace std;

queue<int> q;
vector<int> edges[SIZE];
int times[SIZE];
int dist[SIZE] = {0};
int indeg[SIZE] = {0};

void solution() {
    int N, K, v, result;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> times[i] >> K;
        dist[i] = times[i];
        while (K--) {
            cin >> v;
            edges[i].push_back(v-1);
            indeg[v-1]++;
        }
    }

    for (int i = 0; i < N; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (auto u : edges[v]) {
            dist[u] = max(dist[u], dist[v]+times[u]);
            if (--indeg[u] == 0)
                q.push(u);
        }
    }

    result = 0;
    for (int i = 0; i < N; i++)
        result = max(result, dist[i]);
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}