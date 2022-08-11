#include <iostream>

using namespace std;

void solution() {
    int N, X, a, b;
    long long sum = 0;

    cin >> X >> N;
    while (N--) {
        cin >> a >> b;
        sum += a * b;
    }

    cout << (X == sum ? "Yes" : "No");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}