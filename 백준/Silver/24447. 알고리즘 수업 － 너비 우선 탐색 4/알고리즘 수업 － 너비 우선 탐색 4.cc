#include <iostream>
#include <queue>
#define SIZE 100'000

using namespace std;

vector<int> edges[SIZE];
queue<pair<int, int>> q;
int visited[SIZE][2] = {0}; // 0: depth, 1: visited

void bfs(int root) {
    int visit = 1;

    visited[root][0] = 0;
    q.emplace(root, 0);

    while (!q.empty()) {
        int v = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (visited[v][1] > 0) continue;
        visited[v][0] = depth;
        visited[v][1] = visit++;

        for (int next: edges[v]) {
            if (!visited[next][1])
                q.emplace(next, depth + 1);
        }
    }
}

void solution() {
    int N, M, R, x, y;
    long long result = 0;

    cin >> N >> M >> R;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        x--, y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    R--;

    bfs(R);

    for (int i = 0; i < N; i++) {
        result += (long long) visited[i][0] * visited[i][1];
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}