#include <iostream>
#include <queue>
#define INF 10000000

using namespace std;

vector<pair<int, int>> edges[100];
priority_queue<pair<int, pair<int, int>>> q;
int dist[100][10001];

void initArray(int N) {
    while (!q.empty())
        q.pop();

    for (int i = 0; i < N; ++i) {
        edges[i].clear();
        for (int j = 0; j <= 10000; ++j)
            dist[i][j] = INF * (i > 0);
    }
}

int getDist(int N, int M) {
    int node, c, d, nextNode, nextC, nextD;
    int END = N-1;

    q.emplace(0, make_pair(0, 0));
    while (!q.empty()) {
        node = q.top().second.first;
        c = q.top().second.second;
        d = -q.top().first;
        q.pop();

        if (dist[node][c] < d) continue;
        if (node == END) return d;

        for (auto edge: edges[node]) {
            nextNode = edge.first;
            nextC = c + edge.second/10000;
            nextD = d + edge.second%10000;
            if (nextC <= M && nextD < dist[nextNode][nextC]) {
                q.emplace(-nextD, make_pair(nextNode, nextC));

                for (; nextC <= M && nextD < dist[nextNode][nextC]; ++nextC)
                    dist[nextNode][nextC] = nextD;
            }
        }
    }

    return -1;
}

void solution() {
    int Tc, N, M, K, u, v, c, d;

    cin >> Tc;
    while (Tc--) {
        cin >> N >> M >> K;
        initArray(N);
        while (K--) {
            cin >> u >> v >> c >> d;
            u--, v--;
            edges[u].emplace_back(v, c*10000+d);
        }

        d = getDist(N, M);
        if (d == -1)
            cout << "Poor KCM\n";
        else
            cout << d << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}