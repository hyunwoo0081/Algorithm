#include <iostream>

using namespace std;

void solution() {
    long long A, B, C, D, P;

    cin >> A >> B >> C >> D;
    for (int i = 0; i < 3; i++) {
        cin >> P;
        cout << ((P-1)%(A+B) < A) + ((P-1)%(C+D) < C) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}