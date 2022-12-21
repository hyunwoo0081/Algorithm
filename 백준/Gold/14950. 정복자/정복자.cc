#include <iostream>
#include <queue>
#define SIZE 10000

using namespace std;

int unions[SIZE];
priority_queue<pair<int, int>> pq;

int findRoot(int x) {
    while (unions[x] >= 0)
        x = unions[x];
    return x;
}

bool joinUnions(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b)
        return false;

    if (unions[a] >= unions[b]) {
        unions[b] = min(unions[b], unions[a]-1);
        unions[a] = b;
    }
    else
        unions[b] = a;
    return true;
}

void solution() {
    int N, M, T, A, B, C, count, minCost;

    cin >> N >> M >> T;
    while (M--) {
        cin >> A >> B >> C;
        pq.emplace(-C, (A-1)*SIZE+(B-1));
    }

    for (int i = 0; i < N; i++)
        unions[i] = -1;

    count = 0;
    minCost = 0;
    while (count < N-1) {
        A = pq.top().second/SIZE;
        B = pq.top().second%SIZE;
        C = -pq.top().first;
        pq.pop();

        if (joinUnions(A, B)) {
            count++;
            minCost += C;
        }
    }

    cout << minCost + (N-1)*(N-2)/2*T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}