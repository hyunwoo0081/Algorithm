#include <iostream>

using namespace std;

void solution() {
    int T, A, B, sa, sb;

    sa = sb = 0;
    cin >> T;
    while (T--) {
        cin >> A >> B;

        if (A > B)
            sa += A + B;
        else if (A == B) {
            sa += A;
            sb += B;
        }
        else
            sb += A + B;
    }

    cout << sa << ' ' << sb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}