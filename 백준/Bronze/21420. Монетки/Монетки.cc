#include <iostream>

using namespace std;

void solution() {
    int N, a, cnt = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        cnt += a;
    }

    cout << min(cnt, N - cnt);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}