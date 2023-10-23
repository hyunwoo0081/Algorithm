#include <iostream>

using namespace std;

int arr[5];

void solution() {
    int T, N, M, maxC, a;

    cin >> T;
    while (T--) {
        cin >> N >> M;

        for (auto &c : arr)
            c = 0;

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                cin >> a;
                arr[n] += a;
            }
        }

        maxC = 0;
        for (int n = 0; n < N; n++) {
            if (arr[maxC] < arr[n])
                maxC = n;
        }

        cout << maxC+1 << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}