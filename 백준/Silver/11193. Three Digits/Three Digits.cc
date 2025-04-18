#include <iomanip>
#include <iostream>
#define SIZE 10000000

using namespace std;

long long pow(long long N, long long K) {
    long long result = 1;
    while (K > 0) {
        if (K & 1)
            result = (result * N) % SIZE;
        N = (N * N) % SIZE;
        K >>= 1;
    }
    return result;
}

void solution() {
    long long N, result = 1, cnt2=0, cnt5=0;
    bool isFull = false;

    cin >> N;
    while (N > 1) {
        int tmp = N--;

        while (tmp % 10 == 0)
            tmp /= 10;

        while (tmp % 2 == 0) {
            tmp /= 2;
            cnt2++;
        }

        while (tmp % 5 == 0) {
            tmp /= 5;
            cnt5++;
        }

        int m = min(cnt2, cnt5);
        cnt2 -= m;
        cnt5 -= m;

        result = (result * tmp) % SIZE;
        isFull |= (result >= 1000);
    }

    result = (result * pow(2, cnt2)) % SIZE;
    result = (result * pow(5, cnt5)) % SIZE;

    isFull |= (result >= 1000);

    if (isFull) {
        cout << setfill('0') << setw(3) << result % 1000;
    }
    else {
        cout << result % 1000;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}