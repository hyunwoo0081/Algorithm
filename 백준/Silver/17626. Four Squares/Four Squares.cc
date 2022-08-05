#include <iostream>
#include <queue>
#define SIZE 50'001

using namespace std;

queue<pair<int, int>> q;
int dist[SIZE] = {0};

void solution() {
    int N, node, d, next;

    cin >> N;
    for (int i = 1; i*i < SIZE; i++) {
        dist[i*i] = 1;
        q.emplace(i*i, 1);
    }

    while (!q.empty()) {
        node = q.front().first;
        d = q.front().second;
        q.pop();

        if (d > dist[node]) continue;
        if (node == N) break;

        for (int i = 1; i*i < SIZE; i++) {
            next = node + i*i;
            if (next < SIZE && dist[next] == 0) {
                dist[next] = d+1;
                q.emplace(next, d+1);
            }
        }
    }

    cout << dist[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}