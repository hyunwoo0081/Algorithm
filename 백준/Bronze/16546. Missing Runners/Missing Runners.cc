#include <iostream>

using namespace std;

void solution() {
    long long n, a, sum;

    cin >> n;
    sum = 0;
    for (int i = 1; i < n; i++) {
        cin >> a;
        sum += a;
    }

    cout << n*(n+1)/2 - sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}