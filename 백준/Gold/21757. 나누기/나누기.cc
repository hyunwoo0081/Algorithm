#include <iostream>
#define SIZE 100'001

using namespace std;
typedef long long ll;

ll prefix[SIZE] = {0};
ll counts[3][SIZE] = {0};

void solution() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    ll div = prefix[N]/4;
    if (prefix[N] != div*4) {
        cout << 0;
        return;
    }

    for (int i = 1; i <= N; i++) {
        counts[0][i] = (prefix[i] == div);
        counts[0][i] += counts[0][i-1];
    }

    for (int k = 1; k < 3; k++) {
        for (int i = 1; i < N; i++) {
            if (prefix[i] == div*(k+1))
                counts[k][i] = counts[k-1][i-1];
            counts[k][i] += counts[k][i-1];
        }
    }

    cout << counts[2][N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
