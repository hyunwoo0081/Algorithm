#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int N, M, P, cnt = 0;

    cin >> N >> M >> P;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (2*(i+j) < P) continue;

            cnt += (N-i+1)*(M-j+1);
        }
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}