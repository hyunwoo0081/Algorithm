#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a, a);
}

void solution() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int sum = a*d + c*b;
    int mul = b*d;
    int div = gcd(min(sum, mul), max(sum, mul));

    cout << sum/div << ' ' << mul/div;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
