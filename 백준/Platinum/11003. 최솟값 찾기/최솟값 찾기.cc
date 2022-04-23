#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

priority_queue<pair<int, int>> minQ;

void solution() {
    int N, L, i, A;

    cin >> N >> L;
    for (i = 0; i < N; ++i) {
        cin >> A;
        minQ.emplace(-A, i);

        while (minQ.top().second < i-L+1)
            minQ.pop();

        cout << -minQ.top().first << ' ';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}