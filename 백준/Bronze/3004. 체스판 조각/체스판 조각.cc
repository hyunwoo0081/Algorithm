#include <iostream>

using namespace std;

void solution() {
    int N, a, b;

    cin >> N;
    a = N / 2;
    b = N - a;

    cout << (a+1) * (b+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}