#include <iostream>
#include <queue>
#define SIZE 1000

using namespace std;

priority_queue<pair<int, int>> pq;

int unions[SIZE];

int findRoot(int x) {
    while (unions[x] >= 0)
        x = unions[x];
    return x;
}

bool joinUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b)
        return false;

    if (-unions[a] >= -unions[b]) {
        unions[a] = min(unions[a], unions[b]-1);
        unions[b] = a;
    }
    else {
        unions[a] = b;
    }
    return true;
}


void solution() {
    int N, M, K, u, v, w, minCost;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        unions[i] = -1;
    N -= K-1;

    cin >> u;
    u--;
    while (--K) {
        cin >> v;
        joinUnion(u, --v);
        u = v;
    }

    while (M--) {
        cin >> u >> v >> w;
        u--, v--;
        pq.emplace(-w, u*SIZE+v);
    }

    minCost = 0;
    while (--N) {
        do {
            u = pq.top().second / SIZE;
            v = pq.top().second % SIZE;
            w = -pq.top().first;
            pq.pop();
        } while (!joinUnion(u, v));
        minCost += w;
    }
    cout << minCost;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}