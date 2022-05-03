#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 10000

using namespace std;

priority_queue<pair<int, int>> edges;
int unions[SIZE];

int findRoot(int a) {
    while (unions[a] >= 0)
        a = unions[a];
    return a;
}

bool joinUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return false;

    if (-unions[a] > -unions[b]) {
        unions[b] = a;
    }
    else {
        unions[b] = min(unions[a]-1, unions[b]);
        unions[a] = b;
    }

    return true;
}

void solution() {
    int V, E, A, B, C;

    cin >> V >> E;
    for (int i = 0; i < V; ++i)
        unions[i] = -1;
    for (int i = 0; i < E; ++i) {
        cin >> A >> B >> C;
        edges.emplace(-C, (A-1)*SIZE + B-1);
    }

    int treeWeight = 0;
    int start, end, weight;
    while (!edges.empty()) {
        start = edges.top().second / SIZE;
        end = edges.top().second % SIZE;
        weight = -edges.top().first;
        edges.pop();

        if (joinUnion(start, end)) {
            treeWeight += weight;
        }
    }

    cout << treeWeight;
}

int main() {
    fastIO();
    solution();

    return 0;
}