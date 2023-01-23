#include <iostream>
#define INF 9876543210

using namespace std;
typedef long long ll;

bool isDecreasing(ll n) {
    if (n == 0) return true;

    ll low = -1;
    while (n > 0) {
        if (low >= n%10)
            return false;
        low = n%10;
        n /= 10;
    }
    return true;
}

ll nextNum(ll n) {
    ll stack[10] = {0};
    int stackSize = 0;

    while (n > 0) {
        stack[stackSize++] = n % 10;
        n /= 10;
    }

    for (int i = 1; i < stackSize; i++) {
        if (stack[i] <= stack[i-1]) {
            stack[i-1] = i-1;
            stack[i]++;
        }
    }

    if (stack[stackSize-1] == 10) {
        stack[stackSize] = stackSize;
        stack[stackSize-1] = stackSize-1;
        stackSize++;
    }

    n = 0;
    for (int i = stackSize-1; i >= 0; i--)
        n = n*10 + stack[i];
    return n;
}

void solution() {
    ll N;

    cin >> N;
    N++;
    for (ll n = 0; n <= INF; n++) {
        if (!isDecreasing(n))
            n = nextNum(n) - 1;
        else if (--N == 0) {
            cout << n;
            return;
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}