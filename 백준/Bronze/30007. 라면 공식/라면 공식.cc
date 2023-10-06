#include <iostream>

using namespace std;

void solution() {
    int T, A, B, X;

    cin >> T;
    while (T--) {
        cin >> A >> B >> X;
        cout << A * (X - 1) + B << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}