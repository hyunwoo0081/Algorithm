#include <iostream>

using namespace std;

void solution() {
    long long N, a, b, A, B;

    a = b = 0;
    cin >> N;
    while (N--) {
        cin >> A >> B;

        a += A > B;
        b += A < B;
    }
    cout << a << ' ' << b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}