#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 32000

using namespace std;

bool visited[SIZE] = {false};
int connectedCount[SIZE] = {0};
priority_queue<int> q;
vector<int> edges[SIZE];

void solution() {
    int N, M, A, B;

    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        A--, B--;
        edges[A].push_back(B);
        connectedCount[B]++;
    }

    for (int i = 0; i < N; ++i) {
        if (connectedCount[i] == 0)
            q.push(-i);
    }

    int node;
    while (!q.empty()) {
        node = -q.top();
        q.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        for (auto nextNode: edges[node]) {
            connectedCount[nextNode]--;
            if (!visited[nextNode] && connectedCount[nextNode] <= 0)
                q.push(-nextNode);
        }
        cout << node+1 << ' ';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}