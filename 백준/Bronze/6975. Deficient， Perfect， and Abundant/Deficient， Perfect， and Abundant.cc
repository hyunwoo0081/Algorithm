#include <iostream>

using namespace std;

void solution() {
    int T, N, result;

    cin >> T;
    while (T--) {
        cin >> N;

        result = 1;
        for (int i = 2; i*i <= N; i++) {
            if (N % i) continue;
            if (i*i == N)
                result += i;
            else
                result += i + N / i;
        }

        cout << N << " ";
        if (result < N)
            cout << "is a deficient number.\n\n";
        else if (result == N)
            cout << "is a perfect number.\n\n";
        else
            cout << "is an abundant number.\n\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}