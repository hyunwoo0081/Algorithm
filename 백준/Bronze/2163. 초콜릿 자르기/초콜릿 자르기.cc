#include <iostream>

using namespace std;

int getCount(int N, int M) {
    int tmp;
    if (N == 1 && M == 1)
        return 0;

    if (M > N) {
        tmp = M;
        M = N;
        N = tmp;
    }
    tmp = N/2;
    return getCount(N-tmp, M) + getCount(tmp, M) + 1;
}

void solution() {
    int N, M;
    cin >> N >> M;
    cout << getCount(N, M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}