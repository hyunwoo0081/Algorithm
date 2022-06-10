#include <iostream>

using namespace std;

long long getZ(long long x) {
    if (x <= 0) return 0;
    if (x == 1) return 1;

    long long digit = 2, nOf2 = 4;
    while (nOf2-1 <= x)
        ++digit, nOf2 <<= 1;
    --digit, nOf2 >>= 1;

    long long sum = (nOf2>>1)*digit;

    if (x >= nOf2)
        sum += getZ(x-nOf2) + x-nOf2+1;

    return sum;
}

void solution() {
    long long A, B;
    cin >> A >> B;
    cout << getZ(B) - getZ(A-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}