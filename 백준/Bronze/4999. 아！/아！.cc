#include <iostream>

using namespace std;

void solution() {
    string a, b;
    cin >> a >> b;
    cout << (a.length() >= b.length() ? "go" : "no");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}