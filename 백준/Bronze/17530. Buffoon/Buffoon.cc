#include <iostream>

using namespace std;

void solution() {
    int T, N, maxN;
    bool isWin = true;

    cin >> T >> maxN;
    T--;
    while (T--) {
        cin >> N;
        isWin &= maxN >= N;
    }

    cout << (isWin ? "S" : "N");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}