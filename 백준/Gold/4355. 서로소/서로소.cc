#include <iostream>

using namespace std;

int euilor(int N) {
    int result = 1;

    if (N == 1)
        return 0;

    for (int i = 2; i*i <= N; i++) {
        if (N % i == 0) {
            N /= i;
            result *= i-1;

            while (N % i == 0) {
                N /= i;
                result *= i;
            }
        }
    }

    if (N > 1)
        result *= N-1;

    return result;
}

void solution() {
    int N;

    cin >> N;
    while (N != 0) {
        cout << euilor(N) << '\n';
        cin >> N;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}