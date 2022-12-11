#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int tmp;
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    return a == 0 ? b : gcd(b%a, a);
}

void solution() {
    int n, a, b;
    cin >> n >> a >> b;
    a = gcd(a, b);
    if (n == 3) {
        cin >> b;
        a = gcd(a, b);
    }

    for (int i = 1; i <= a; i++)
        if (a % i == 0)
            cout << i << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}