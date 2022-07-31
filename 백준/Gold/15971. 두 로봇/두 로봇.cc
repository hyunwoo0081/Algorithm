#include <iostream>
#include <queue>
#define SIZE 100'000

using namespace std;

queue<pair<int, int>> q;
vector<pair<int, int>> edges[SIZE];
bool visited[SIZE] = {false};

int getMinDist(int start, int end) {
    int len, node, nLen, next, maxE;
    visited[start] = true;
    q.emplace(0, start*1001);

    while (!q.empty()) {
        len = q.front().first;
        node = q.front().second / 1001;
        maxE = q.front().second % 1001;
        q.pop();

        if (node == end)
            return len - maxE;

        for (auto edge : edges[node]) {
            next = edge.first;
            nLen = len + edge.second;
            if (!visited[next]) {
                q.emplace(nLen, next*1001 + max(maxE, edge.second));
                visited[next] = true;
            }
        }
    }

    return 0;
}

void solution() {
    int N, start, end, a, b, len;

    cin >> N >> start >> end;
    start--, end--;

    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >> len;
        a--, b--;
        edges[a].emplace_back(b, len);
        edges[b].emplace_back(a, len);
    }

    cout << getMinDist(start, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}