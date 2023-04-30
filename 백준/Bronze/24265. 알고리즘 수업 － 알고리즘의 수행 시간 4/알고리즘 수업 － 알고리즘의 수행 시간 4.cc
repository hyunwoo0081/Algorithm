#include <iostream>

using namespace std;

void solution() {
    long long N;
    cin >> N;
    cout << N*(N-1)/2 << '\n' << 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}