#include <iostream>

using namespace std;

void solution() {
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    cout << (a1 >= c && c*n0 <= a1*n0+a0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}