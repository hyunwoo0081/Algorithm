#include <iostream>
#define MOD 1000007

using namespace std;

void solution() {
    int a, b, c, m;
    cin >> m;

    a = b = 1;
    while (--m) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    cout << a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}