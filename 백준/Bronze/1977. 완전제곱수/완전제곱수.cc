#include <iostream>

using namespace std;

void solution() {
    int N, M, sum, x;
    cin >> N >> M;

    sum = 0;
    for (int i = 1; i*i <= M; i++) {
        if (N <= i*i) {
            if (sum == 0)
                x = i*i;
            sum += i*i;
        }
    }

    if (sum == 0)
        cout << -1;
    else
        cout << sum << '\n' << x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}