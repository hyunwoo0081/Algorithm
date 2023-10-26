#include <iostream>

using namespace std;

void solution() {
    int T, n;

    cin >> T;
    while (T--) {
        cin >> n;
        cout << ((n&(-n)) == n) << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}