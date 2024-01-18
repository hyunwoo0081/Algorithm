#include <iostream>

using namespace std;

void solution() {
    int n, k, a, b;

    cin >> n >> k >> a >> b;
    cout << (n-1 + k-1)*b << ' ' << (n-1)*a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}