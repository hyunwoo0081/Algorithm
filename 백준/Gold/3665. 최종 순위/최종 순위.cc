#include <iostream>
#include <queue>
#define SIZE 500

using namespace std;

bool edges[SIZE][SIZE];
bool visited[SIZE];
int inputEdges[SIZE];
int topo[SIZE];
int topoSize;

queue<int> q;

void solution() {
    int T, n, m, a, b, startNode, node;

    cin >> T;
    while (T--) {
        //init
        cin >> n;
        while (!q.empty()) q.pop();
        for (int y = 0; y < n; y++) {
            visited[y] = false;
            for (int x = 0; x < n; x++)
                edges[y][x] = false;
        }

        //edges
        for (int i = 0; i < n; i++) {
            cin >> topo[i];
            topo[i]--;
            for (int j = 0; j < i; j++)
                edges[topo[j]][topo[i]] = true;
        }

        cin >> m;
        while (m--) {
            cin >> a >> b;
            a--, b--;
            edges[a][b] = !edges[a][b];
            edges[b][a] = !edges[b][a];
        }

        for (int i = 0; i < n; i++) {
            inputEdges[i] = 0;
            for (int j = 0; j < n; j++)
                inputEdges[i] += edges[j][i];

            if (inputEdges[i] == 0)
                startNode = i;
        }

        //topologicalSort
        topoSize = 0;
        if (inputEdges[startNode] == 0) {
            q.push(startNode);
            visited[startNode] = true;
            topo[topoSize++] = startNode+1;
        }

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                if (edges[node][i] && !visited[i] && (--inputEdges[i]) == 0) {
                    q.push(i);
                    visited[i] = true;
                    topo[topoSize++] = i+1;
                }
            }
        }


        if (topoSize != n)
            cout << "IMPOSSIBLE\n";
        else {
            for (int i = 0; i < topoSize; i++)
                cout << topo[i] << ' ';
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}