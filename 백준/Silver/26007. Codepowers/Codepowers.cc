#include <iostream>
#include <algorithm>
#define SIZE 100001

using namespace std;

int cnts[SIZE] = {0, };
void solution() {
    long long N, M, K, X, a, b;

    cin >> N >> M >> K >> X;
    cnts[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;
        X += a;
        cnts[i+1] += cnts[i] + (X < K);
    }

    while (M--) {
        cin >> a >> b;
        a = max(a, 1LL);
        b = min(b-1, N);
        // cout << cnts[b] << ' ' << cnts[a] << '\n';
        cout << cnts[b] - cnts[a-1] << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}