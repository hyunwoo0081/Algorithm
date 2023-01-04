#include <iostream>
#include <queue>
#define SIZE 1000

using namespace std;

int ins[SIZE] = {0};
int result[SIZE] = {0};
vector<int> nexts[SIZE];
queue<pair<int, int>> q;

void solution() {
    int N, M, A, B, d;

    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        A--, B--;
        nexts[A].push_back(B);
        ins[B]++;
    }

    for (int i = 0; i < N; i++) {
        if (ins[i] == 0) {
            q.emplace(i, 1);
            result[i] = 1;
        }
    }

    while (!q.empty()) {
        A = q.front().first;
        d = q.front().second;
        q.pop();

        for (auto next: nexts[A]) {
            if (--ins[next] == 0) {
                q.emplace(next, d+1);
                result[next] = d+1;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << result[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}