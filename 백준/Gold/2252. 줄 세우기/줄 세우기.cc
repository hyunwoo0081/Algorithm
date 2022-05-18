#include <iostream>
#include <vector>
#include <stack>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

stack<int> s;
vector<int> edges[32000];
bool visited[32000] = {false};

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;

    for (int nextNode: edges[node]) {
        dfs(nextNode);
    }
    s.push(node);
}


void solution() {
    int N, M, A, B;

    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        A--, B--;
        edges[A].push_back(B);
    }

    for (int i = 0; i < N; ++i)
        dfs(i);

    for (int i = 0; i < N; ++i) {
        cout << s.top()+1 << ' ';
        s.pop();
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}