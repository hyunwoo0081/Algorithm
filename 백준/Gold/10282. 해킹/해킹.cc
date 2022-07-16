#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

vector<pair<int,int>> edges[10000];
priority_queue<pair<int, int>> q;
int dist[10000];

void init(int n) {
    while (n--) {
        edges[n].clear();
        dist[n] = INF;
    }
    while (!q.empty())
        q.pop();
}

void printCounts(int startNode, int n) {
    int node, d, nextNode, nextDist;

    q.emplace(0, startNode);
    dist[startNode] = 0;
    while(!q.empty()) {
        d = -q.top().first;
        node = q.top().second;
        q.pop();

        if (d > dist[node]) continue;

        for (auto next : edges[node]) {
            nextNode = next.first;
            nextDist = d + next.second;
            if (nextDist < dist[nextNode]) {
                q.emplace(-nextDist, nextNode);
                dist[nextNode] = nextDist;
            }
        }
    }

    int count = 0, maxTime = 0;
    while (n--) {
        if (dist[n] < INF) {
            count++;
            maxTime = max(maxTime, dist[n]);
        }
    }
    cout << count << ' ' << maxTime << '\n';
}

void solution() {
    int T, n, d, c, a, b, s;

    cin >> T;
    while (T--) {
        cin >> n >> d >> c;
        c--;
        init(n);
        while (d--) {
            cin >> a >> b >> s;
            a--, b--;
            edges[b].emplace_back(a, s);
        }

        printCounts(c, n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}