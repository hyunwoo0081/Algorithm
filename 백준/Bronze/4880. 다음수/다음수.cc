#include <iostream>

using namespace std;

void solution() {
    int a, b, c;

    cin >> a >> b >> c;

    while (a || b || c) {
        if (b-a == c-b && b-a != 0) {
            cout << "AP " << c + (c-b) << '\n';
        }
        else {
            cout << "GP " << c * (c/b) << '\n';
        }

        cin >> a >> b >> c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}