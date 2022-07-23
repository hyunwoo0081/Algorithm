#include <iostream>

using namespace std;

void solution() {
    long long N, M;
    cin >> N >> M;
    cout << abs(N-M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}