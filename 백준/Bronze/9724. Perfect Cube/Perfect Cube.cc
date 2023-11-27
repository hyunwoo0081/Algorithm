#include <iostream>

using namespace std;

void solution() {
    int T, a, b, count;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> a >> b;

        count = 0;
        for (int i = 1; i*i*i <= b; i++) {
            count += a <= i*i*i;
        }
        cout << "Case #" << t << ": " << count << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}