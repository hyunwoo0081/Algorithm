#include <iostream>

using namespace std;

void solution() {
    int T;
    double a;

    cin >> T;
    cout << fixed;
    cout.precision(2);
    while (T--) {
        cin >> a;
        cout << '$' << a * 0.8 << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}