#include <iostream>
#define INF 987654321

using namespace std;

void solution() {
    int N, M, a, b, minA, minB;

    cin >> N >> M;
    minA = minB = INF;
    while (M--) {
        cin >> a >> b;
        minA = min(minA, a);
        minB = min(minB, b);
    }
    cout << min((N+5)/6*minA, min(N*minB, N/6*minA + N%6*minB));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}