#include <iostream>
#include <vector>
#define SIZE 100'000

using namespace std;
typedef long long ll;

bool isQ[SIZE] = {false};
int unions[SIZE];
int unionCount[SIZE] = {0};
vector<pair<int, int>> edges;
vector<int> qStack;

int findRoot(int x) {
    while(unions[x] >= 0)
        x = unions[x];
    return x;
}

ll joinUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return 0;

    int ca = unionCount[a];
    int cb = unionCount[b];
    if (unions[a] < unions[b]) {
        unions[b] = a;
        unionCount[a] += unionCount[b];
    }
    else {
        unions[b] = min(unions[b] , unions[a]-1);
        unions[a] = b;
        unionCount[b] += unionCount[a];
    }

    return (ll) ca * cb;
}

void solution() {
    int N, M, Q, x, y;
    ll count;

    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        unions[i] = -1;
        unionCount[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        edges.emplace_back(x, y);
    }

    for (int i = 0; i < Q; i++) {
        cin >> x;
        x--;
        qStack.push_back(x);
        isQ[x] = true;
    }

    for (int i = 0; i < M; i++) {
        if (!isQ[i])
            joinUnion(edges[i].first, edges[i].second);
    }

    count = 0;
    while (!qStack.empty()) {
        x = qStack.back();
        qStack.pop_back();
        count += joinUnion(edges[x].first, edges[x].second);
    }

    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}