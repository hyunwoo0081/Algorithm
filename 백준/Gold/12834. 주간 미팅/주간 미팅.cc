#include <iostream>
#include <vector>
#define SIZE 1000
#define INF 54321

using namespace std;

int floyd[SIZE][SIZE];
vector<int> list;

void solution() {
    int N, V, E, A, B, a, b, l;

    cin >> N >> V >> E >> A >> B;
    A--, B--;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            floyd[i][j] = i == j ? 0 : INF;

    while (N--) {
        cin >> a;
        list.emplace_back(a-1);
    }

    while (E--) {
        cin >> a >> b >> l;
        a--, b--;
        floyd[a][b] = floyd[b][a] = l;
    }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    int minDist = 0;
    for (auto v:list) {
        minDist += floyd[v][A] == INF ? -1 : floyd[v][A];
        minDist += floyd[v][B] == INF ? -1 : floyd[v][B];
    }
    cout << minDist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}