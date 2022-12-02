#include <iostream>
#define MOD 1'000'000'007

using namespace std;
typedef long long ll;

ll pow(ll a, ll p) {
    if (p == 1) return a;

    if (p % 2 == 0) {
        a = pow(a, p/2);
        a *= a;
    }
    else
        a *= pow(a, p-1);
    return a % MOD;
}

void solution() {
    int M, N, S;
    long long sum, result = 0;

    cin >> M;
    while (M--) {
        cin >> N >> S;
        sum = (S * pow(N, MOD-2)) % MOD;
        result = (result + sum) % MOD;
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