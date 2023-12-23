#include <iostream>

using namespace std;

void solution() {
    int T;
    string a, b;

    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << (a == b ? "OK\n" : "ERROR\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}