#include <iostream>
#include <queue>
#define SIZE 100'000
#define INF 987654321

using namespace std;

int visited[SIZE + 1] = {0};
queue<int> q;

void solution() {
    int N, M, A, B, l, r;

    cin >> N >> M >> A >> B;
    while (M--) {
        cin >> l >> r;
        for (; l <= r; l++) {
            visited[l] = -INF;
        }
    }

    visited[0] = 0;
    q.emplace(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur + A <= N && visited[cur + A] == 0) {
            visited[cur + A] = visited[cur] + 1;
            q.emplace(cur + A);
        }
        if (cur + B <= N && visited[cur + B] == 0) {
            visited[cur + B] = visited[cur] + 1;
            q.emplace(cur + B);
        }
    }

    if (visited[N] <= 0) {
        cout << -1;
    } else {
        cout << visited[N];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}