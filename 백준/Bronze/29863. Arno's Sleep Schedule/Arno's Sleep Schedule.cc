#include <iostream>

using namespace std;

void solution() {
    int N, M;

    cin >> N >> M;
    M -= N;
    if (M < 0) M += 24;
    cout << M;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}