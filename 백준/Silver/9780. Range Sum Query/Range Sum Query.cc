#include <iostream>
#define SIZE 100'001

using namespace std;


long long arr[SIZE] = {-1};
void solution() {
    long long T, N, Q, from, to;

    cin >> T;
    while (T--) {
        cin >> N >> Q;

        if (arr[0] != -1)
            cout << '\n';

        arr[0] = 0;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }

        while (Q--) {
            cin >> from >> to;
            cout << arr[to+1] - arr[from] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}