#include <iostream>

using namespace std;

void solution() {
    int T, N, sum, a;

    cin >> T;
    while (T--) {
        cin >> N;
        sum = 0;
        while (N--) {
            cin >> a;
            sum += a;
        }
        cout << sum << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
