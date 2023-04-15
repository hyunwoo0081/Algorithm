#include <iostream>

using namespace std;
typedef long long ll;

bool isPrime(ll N) {
    if (N < 2) return false;
    for (ll i = 2; i*i <= N; i++)
        if (N % i == 0) return false;
    return true;
}

void solution() {
    int T;
    ll N;

    cin >> T;
    while (T--) {
        cin >> N;
        while (!isPrime(N))
            N++;
        cout << N << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}