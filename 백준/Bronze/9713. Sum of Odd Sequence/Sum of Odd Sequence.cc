#include <iostream>

using namespace std;

void solution() {
    int T, N, d;

    cin >> T;
    while (T--) {
        cin >> N;
        d = N/2;
        cout << (2 + 2*d)*(d+1)/2 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}