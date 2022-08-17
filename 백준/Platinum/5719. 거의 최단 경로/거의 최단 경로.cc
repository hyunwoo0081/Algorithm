#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

vector<pair<int, int>> edges[500];
vector<pair<int, int>> revEdges[500];
bool canMove[500][500];
int dist[500];

int getMinDist(int S, int D, int N) {
    int node, len, next, nLen;
    priority_queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
        dist[i] = INF;

    q.emplace(0, S);
    dist[S] = 0;
    while (!q.empty()) {
        len = -q.top().first;
        node = q.top().second;
        q.pop();

        if (len > dist[node]) continue;
        if (node == D) return len;

        for (auto edge: edges[node]) {
            next = edge.first;
            nLen = len + edge.second;
            if (canMove[node][next] && nLen < dist[next]) {
                q.emplace(-nLen, next);
                dist[next] = nLen;
            }
        }
    }

    return -1;
}

void removeMinEdges(int S, int D, int minLen) {
    int node, prev, len, prevDist;
    queue<pair<int, int>> q;

    q.emplace(D, minLen);
    while(!q.empty()) {
        node = q.front().first;
        len = q.front().second;
        q.pop();

        if (node == S) continue;

        for (auto edge: revEdges[node]) {
            prev = edge.first;
            prevDist = len - edge.second;
            if (canMove[prev][node] && dist[prev] == prevDist) {
                canMove[prev][node] = false;
                q.emplace(prev, prevDist);
            }
        }
    }
}

void solution() {
    int N, M, S, D, U, V, P;

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        cin >> S >> D;

        for (int i = 0; i < N; i++) {
            edges[i].clear();
            revEdges[i].clear();
        }

        while(M--) {
            cin >> U >> V >> P;
            edges[U].emplace_back(V, P);
            revEdges[V].emplace_back(U, P);
            canMove[U][V] = true;
        }

        removeMinEdges(S, D, getMinDist(S, D, N));
        cout << getMinDist(S, D, N) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}