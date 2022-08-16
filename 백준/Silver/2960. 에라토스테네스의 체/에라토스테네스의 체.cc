#include <iostream>

using namespace std;

bool primes[1001] = {false};

void solution() {
    int N, K, P, count;

    count = 0;
    cin >> N >> K;
    for (int i = 2; i <= N; i++) {
        if (primes[i]) continue;
        for (int j = 1; i*j <= N; j++) {
            if (primes[i*j]) continue;
            if (++count == K) P = i*j;
            primes[i*j] = true;
        }
    }

    cout << P;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}