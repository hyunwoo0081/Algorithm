#include <iostream>

using namespace std;

void solution() {
    int T, N, d;

    cin >> T;
    while (T--) {
        cin >> N >> d;
        cout << "You get " << N/d << " piece(s) and your dad gets " << N % d << " piece(s).\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}