#include <iostream>
#define INF 987654321

using namespace std;

int dist[400][400];

void solution() {
    int V, E, a, b, c;
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = INF;

    while (E--) {
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = min(c, dist[a][b]);
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int minNum = dist[0][0];
    for (int k = 1; k < V; k++)
        minNum = min(minNum, dist[k][k]);

    cout << (minNum == INF ? -1 : minNum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}