#include <iostream>

using namespace std;

void solution() {
    int n, a;

    cin >> n >> a;
    if (n >= 6) {
        cout << "Love is open door";
        return;
    }

    for (int i = 1; i < n; i++) {
        a = !a;
        cout << a << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}