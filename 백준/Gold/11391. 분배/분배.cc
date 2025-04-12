#include <iostream>

using namespace std;

void solution() {
    int N, K, twoK, twoN;

    cin >> N >> K;
    twoK = 1 << K;
    twoN = 1 << N;
    for (int y = 0; y < twoK; y++) {
        for (int x = 0; x < twoN; x += 2*twoK) {
            if (x != 0) cout << ' ';
            cout << x+y << " " << x+2*twoK-y-1;
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}