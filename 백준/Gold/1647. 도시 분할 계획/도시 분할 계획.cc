#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 100000

using namespace std;

priority_queue<pair<int, pair<int, int>>> edges;
int unions[SIZE];

int findRoot(int x) {
    while (unions[x] >= 0)
        x = unions[x];
    return x;
}

bool joinUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return false;

    if (-unions[a] > -unions[b]) {
        unions[b] = a;
    }
    else {
        unions[b] = min(unions[a], unions[b]-1);
        unions[a] = b;
    }
    return true;
}

void solution() {
    int N, M, A, B, C;

    cin >> N >> M;
    while (M--) {
        cin >> A >> B >> C;
        edges.emplace(-C, make_pair(A-1, B-1));
    }

    for (int i = 0; i < N; ++i)
        unions[i] = -1;

    int count = 0;
    long long sum = 0;
    while (count < N-2) {
        do {
            C = -edges.top().first;
            A = edges.top().second.first;
            B = edges.top().second.second;
            edges.pop();
        } while (!joinUnion(A, B));

        sum += C;
        count++;
    }

    cout << sum;
}

int main() {
    fastIO();
    solution();

    return 0;
}