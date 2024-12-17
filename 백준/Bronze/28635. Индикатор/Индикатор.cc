#include <iostream>

using namespace std;

int solution() {
    int m, a, b;

    cin >> m >> a >> b;
    cout << (m+b-a) % m;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}