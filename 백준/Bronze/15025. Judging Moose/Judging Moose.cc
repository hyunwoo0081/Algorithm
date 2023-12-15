#include <iostream>

using namespace std;

void solution() {
    int a, b;

    cin >> a >> b;
    if (a == 0 && b == 0) {
        cout << "Not a moose";
    }
    else {
        cout << (a == b ? "Even " : "Odd ");
        cout << max(a, b) * 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}