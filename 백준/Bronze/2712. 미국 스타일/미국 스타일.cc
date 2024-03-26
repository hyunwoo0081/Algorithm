#include <iostream>

using namespace std;

void solution() {
    int T;
    double n;
    string s;

    cin >> T;
    while (T--) {
        cin >> n >> s;
        cout << fixed;
        cout.precision(4);

        if (s == "kg")
            cout << 2.2046 * n << " lb\n";
        else if (s == "lb")
            cout << 0.4536 * n << " kg\n";
        else if (s == "l")
            cout << 0.2642 * n << " g\n";
        else if (s == "g")
            cout << 3.7854 * n << " l\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}