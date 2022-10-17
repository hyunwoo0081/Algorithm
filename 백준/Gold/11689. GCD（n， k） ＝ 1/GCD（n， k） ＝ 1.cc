#include <iostream>

using namespace std;
typedef long long ll;

void solution() {
    ll n, result = 1;

    cin >> n;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            result *= i-1;
            n /= i;

            while (n % i == 0) {
                result *= i;
                n /= i;
            }
        }

    }

    if (n != 1)
        result *= n - 1;

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
