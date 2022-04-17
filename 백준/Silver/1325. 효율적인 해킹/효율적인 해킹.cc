#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 10000

using namespace std;

vector<int> edge[SIZE];
bool visited[SIZE];
int counts[SIZE] = {0};

void dfs(int node) {
    if (visited[node]) return;

    visited[node] = true;
    for (int nextNode: edge[node])
        dfs(nextNode);
}

int getCount(int node, int N) {
    for (int j = 0; j < N; ++j)
        visited[j] = false;
    dfs(node);
    int c = 0;
    for (int i = 0; i < N; ++i) {
        if(visited[i]) c++;
    }

    return c;
}

void solution() {
    int N, M, a, b, maxCount;

    cin >> N >> M;
    while (M--) {
        cin >> a >> b;
        edge[b-1].push_back(a-1);
    }
    maxCount = -1;
    for (int i = 0; i < N; ++i) {
        counts[i] = getCount(i, N);
        maxCount = max(maxCount, counts[i]);
    }
    
    for (int i = 0; i < N; ++i) {
        if (counts[i] == maxCount) cout << i+1 << ' ';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}