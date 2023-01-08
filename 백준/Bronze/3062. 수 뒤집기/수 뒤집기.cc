#include <iostream>

using namespace std;



void solution() {
    int T, N, R, tmp;

    cin >> T;
    while (T--) {
        cin >> N;
        tmp = N;
        R = 0;
        while (tmp > 0) {
            R = R*10 + tmp%10;
            tmp /= 10;
        }
        N += R;

        tmp = N;
        R = 0;
        while (tmp > 0) {
            R = R*10 + tmp%10;
            tmp /= 10;
        }
        cout << (N == R ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}