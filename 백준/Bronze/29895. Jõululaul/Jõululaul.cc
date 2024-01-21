#include <iostream>

using namespace std;

void solution() {
    long long T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << i * (T-i + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}