#include <iostream>
#define MOD 1000000007

using namespace std;

long long pow5s[27] = {1, 5};

void solution() {
    int Q, N;

    for (int i = 2; i < 27; i++) {
        pow5s[i] = (pow5s[i-1] * pow5s[i-1]) % MOD;
    }

    cin >> Q;
    while (Q--) {
        cin >> N;

        if (N == 1) {
            cout << 5 << '\n';
            continue;
        }

        N--;
        long long result = 4;
        for (int i = 0; (1<<i) <= N; i++) {
            if (N & (1<<i))
                result = (result * pow5s[i+1]) % MOD;
        }

        cout << result << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}