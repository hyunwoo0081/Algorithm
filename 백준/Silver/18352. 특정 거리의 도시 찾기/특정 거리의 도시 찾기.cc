#include <iostream>
#include <vector>
#include <queue>
#define SIZE 300000

using namespace std;

vector<int> edges[SIZE];
queue<pair<int, int>> q;
int visited[SIZE] = {0};

void solution() {
    int N, M, K, X, a, b, node, dist;
    bool isPrinted = false;

    cin >> N >> M >> K >> X;
    X--;

    for (int i = 0; i < N; i++)
        visited[i] = -1;

    while (M--) {
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
    }

    q.emplace(X, 0);
    visited[X] = 0;
    while (!q.empty()) {
        node = q.front().first;
        dist = q.front().second;
        q.pop();

        if (dist >= K) continue;

        for (int next : edges[node]) {
            if (visited[next] < 0) {
                q.emplace(next, dist + 1);
                visited[next] = dist + 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == K) {
            isPrinted = true;
            cout << i+1 << '\n';
        }
    }

    if (!isPrinted)
        cout << -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}