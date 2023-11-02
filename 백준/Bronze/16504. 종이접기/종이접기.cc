#include <iostream>

using namespace std;

void solution() {
    long long N, a, sum;

    cin >> N;

    sum = 0;
    for (int i = 0; i < N*N; i++) {
        cin >> a;
        sum += a;
    }
    cout << sum;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}