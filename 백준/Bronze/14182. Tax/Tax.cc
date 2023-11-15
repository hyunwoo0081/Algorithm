#include <iostream>

using namespace std;

void solution() {
    long long n;

    cin >> n;
    while (n > 0) {
        if (n <= 1000000)
            cout << n << '\n';
        else if (n <= 5000000)
            cout << n * 9 / 10 << '\n';
        else
            cout << n * 8 / 10 << '\n';

        cin >> n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}