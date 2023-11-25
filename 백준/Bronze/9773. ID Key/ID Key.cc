#include <iostream>

using namespace std;

void solution() {
    long long T, n, tmp, result;

    cin >> T;
    while (T--) {
        cin >> n;

        result = 0;
        tmp = n;
        while (tmp > 0) {
            result += tmp % 10;
            tmp /= 10;
        }

        result += (n % 1000) * 10;

        if (result < 1000)
            result += 1000;
        result = result % 10000;

        // output
        if (result < 10)
            cout << "000" << result << '\n';
        else if (result < 100)
            cout << "00" << result << '\n';
        else if (result < 1000)
            cout << "0" << result << '\n';
        else
            cout << result << '\n';

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}