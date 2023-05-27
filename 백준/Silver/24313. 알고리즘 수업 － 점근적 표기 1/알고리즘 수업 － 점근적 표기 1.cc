#include <iostream>

using namespace std;

void solution() {
    int a1, a2, c, n0;

    cin >> a1 >> a2 >> c >> n0;
    cout << (a1 <= c && a1*n0+a2 <= c*n0);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}