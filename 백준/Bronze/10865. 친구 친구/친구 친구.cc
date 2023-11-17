#include <iostream>
#define SIZE 100000
using namespace std;

int counts[SIZE] = {0};

void solution() {
    int N, M, a, b;

    cin >> N >> M;
    while (M--) {
        cin >> a >> b;
        a--, b--;
        counts[a]++;
        counts[b]++;
    }

    for (int i = 0; i < N; i++)
        cout << counts[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}