#include <iostream>

using namespace std;

void solution() {
    int a, b;

    cin >> a >> b;
    cout << b + b-a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}