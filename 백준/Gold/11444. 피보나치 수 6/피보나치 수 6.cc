#include <iostream>
#include <unordered_map>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define MOD 1'000'000'007

using namespace std;

typedef long long ll;

unordered_map<ll, ll> fibonacci;

ll getFibonacci(ll N) {
    if (N == 0) return 0;
    if (fibonacci[N] > 0) return fibonacci[N];

    ll K = N/2;
    return fibonacci[N] = ((getFibonacci(K+1)*getFibonacci(N-K))%MOD + (getFibonacci(K)*getFibonacci(N-K-1))%MOD) % MOD;
}

void solution() {
    ll N;
    cin >> N;

    fibonacci[1] = fibonacci[2] = 1;
    fibonacci[3] = 2;

    cout << getFibonacci(N);
}

int main() {
    fastIO();
    solution();

    return 0;
}