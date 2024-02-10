#include <iostream>

using namespace std;

void solution() {
    int N, result;

    cin >> N;
    result = 0;
    for (int i = 1; i*i <= N; i++) {
        if (N % i == 0) {
            result += i;
            if (i != N/i)
                result += N/i;
        }
    }

    cout << result * 5 - 24;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}