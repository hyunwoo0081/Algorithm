#include <iostream>
#define MOD 16769023

using namespace std;

void solution() {
    long long N, result = 1;

    cin >> N;
    for (int i = 0; i < N; i += 2) {
        result = (result * 2) % MOD;
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}