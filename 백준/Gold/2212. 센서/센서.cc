#include <iostream>
#include <algorithm>
#define SIZE 10000

using namespace std;

int pos[SIZE];
int counts[SIZE];

void solution() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> pos[i];

    if (N <= K) {
        cout << 0;
        return;
    }

    sort(pos, pos+N);
    for (int i = 1; i < N; ++i) {
        counts[i-1] = pos[i] - pos[i-1];
    }
    sort(counts, counts+N-1);

    int sum = pos[N-1]-pos[0];
    for (int i = 0; i < K-1; ++i) {
        sum -= counts[N-2-i];
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