#include <iostream>

using namespace std;

void solution() {
    int a, sum;

    sum = 0;
    while (cin >> a)
        sum += a;
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}