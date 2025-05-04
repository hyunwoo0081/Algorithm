#include <iostream>

using namespace std;

void solution() {
    long long N, w, d, sum;

    while (cin >> N >> w >> d >> sum) {
        long long total = N*(N-1)/2 * w;

        if (total == sum) {
            cout << N << '\n';
            continue;
        }

        long long result = (total - sum) / d;
        cout << result << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}