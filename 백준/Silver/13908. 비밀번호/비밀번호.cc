#include <iostream>

using namespace std;

int getCount(int essential, int depth) {
    if (depth == 0) {
        return (int) (essential == 0);
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += getCount(essential & ~(1 << i), depth - 1);
    }

    return sum;
}

void solution() {
    int N, M, K, essential = 0;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> K;
        essential |= (1 << K);
    }

    cout << getCount(essential, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}