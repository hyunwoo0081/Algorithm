#include <iostream>

using namespace std;

void solution() {
    int N, count;

    cin >> N;
    N = 1000 - N;

    count = 0;
    count += N / 500;
    N %= 500;
    count += N / 100;
    N %= 100;
    count += N / 50;
    N %= 50;
    count += N / 10;
    N %= 10;
    count += N / 5;
    N %= 5;
    count += N / 1;

    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
