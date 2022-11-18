#include <iostream>
#include <vector>
#define SIZE 500

using namespace std;

vector<int> edges[SIZE];
bool visited[SIZE];

bool isTree(int node, int prevNode) {
    bool result = true;
    if (visited[node])
        return false;

    visited[node] = true;
    for (auto next : edges[node]) {
        if (next != prevNode)
            result &= isTree(next, node);
    }
    return result;
}

void solution() {
    int n, m, t, a, b;

    t = 0;
    cin >> n >> m;
    while (!(n == 0 && m == 0)) {
        // init
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            edges[i].clear();
        }

        while (m--) {
            cin >> a >> b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
            count += isTree(i, -1);

        //output
        cout << "Case " << ++t << ": ";
        if (count == 0)
            cout << "No trees.\n";
        else if (count == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << count << " trees.\n";

        cin >> n >> m;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
