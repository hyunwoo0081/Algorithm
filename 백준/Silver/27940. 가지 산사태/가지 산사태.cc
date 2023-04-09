#include <iostream>
#define INF 987654321

using namespace std;

void solution() {
    int N, M, K, t, r, sum = 0, floor = INF;

    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        cin >> t >> r;
        sum += r;
        floor = min(floor, t);
        if (sum > K) {
            cout << i << ' ' << floor;
            return;
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}