#include <iostream>

using namespace std;

void solution() {
    long long D, N, M, K, mandu, bock, m, b;

    cin >> D >> N >> M >> K;

    N = (D - N%D) % D;
    M = (D - M%D) % D;

    mandu = bock = 0;
    if (K >= N && N > 0) {
        m = 1 + (K-N) / D;
        b = (K-N);

        if (m > mandu || m == mandu && b > bock) {
            mandu = m, bock = b;
        }
    }

    if (K >= M && N > 0) {
        m = 1 + (K-M) / D;
        b = (K-M);

        if (m > mandu || m == mandu && b > bock) {
            mandu = m, bock = b;
        }
    }

    if (K >= M+N && M > 0 && N > 0) {
        m = 1+1 + (K-M-N) / D;
        b = K - M - N;

        if (m > mandu || m == mandu && b > bock) {
            mandu = m, bock = b;
        }
    }

    m = K / D;
    b = K;
    if (m > mandu || m == mandu && b > bock) {
        mandu = m, bock = b;
    }

    cout << bock;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}