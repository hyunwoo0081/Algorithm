#include <iostream>

using namespace std;

void solution() {
    int N, r, deg;
    long long count;

    cin >> N;

    count = 0;
    r = 10;
    deg = 1;
    while (r <= N) {
        count += (r - r/10) * deg;
        r *= 10;
        deg++;
    }
    count += (N - r/10 + 1) * deg;

    cout << count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}