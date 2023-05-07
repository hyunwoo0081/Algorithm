#include <iostream>

using namespace std;

void solution() {
    long long N;
    cin >> N;
    cout << ((1 << N) + 1)*((1 << N)+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}