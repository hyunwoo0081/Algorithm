#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int inDegree[500] = {0};
int times[500];
int minimum[500] = {0};
vector<int> edges[500];
queue<int> q;

void solution() {
    int N, edge;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> times[i];

        cin >> edge;
        while (edge >= 0) {
            edges[edge-1].push_back(i);
            inDegree[i]++;
            cin >> edge;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
            minimum[i] = times[i];
        }
    }

    while (!q.empty()) {
        int target = q.front();
        q.pop();

        for (int e : edges[target]) {
            minimum[e] = max(minimum[e], times[e]+minimum[target]);
            if (--inDegree[e] == 0)
                q.push(e);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << minimum[i] << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}