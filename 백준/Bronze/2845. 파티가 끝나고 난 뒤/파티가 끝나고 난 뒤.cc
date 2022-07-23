#include <iostream>

using namespace std;

void solution() {
    int L, P, N, a;
    cin >> L >> P;
    N = L*P;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        cout << a-N << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}