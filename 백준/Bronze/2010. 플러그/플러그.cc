#include <iostream>

using namespace std;

void solution() {
    int N, a;
    long long sum = 0;
    cin >> N;
    sum -= N-1;
    while (N--) {
        cin >> a;
        sum += a;
    }
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}