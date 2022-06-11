#include <iostream>

using namespace std;

long long getZ(long long x) {
    if (x <= 0) return 0;
    if (x == 1) return 1;

    int digit;
    for (digit = 2; (1LL<<digit)-1 <= x; ++digit);
    --digit;

    long long sum = (1LL<<digit)*digit/2;

    if (x >= (1LL<<digit))
        sum += getZ(x-(1LL<<digit)) + x-(1LL<<digit)+1;

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