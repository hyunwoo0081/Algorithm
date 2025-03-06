#include <iostream>

using namespace std;

void solution() {
    int A, B, result;
    char C;

    cin >> A >> C >> B;
    while (A != 0 || B != 0 || C != 'W') {
        result = (C == 'D') ? A + B : A - B;

        if (result < -200) {
            cout << "Not allowed" << '\n';
        } else {
            cout << result << '\n';
        }

        cin >> A >> C >> B;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}