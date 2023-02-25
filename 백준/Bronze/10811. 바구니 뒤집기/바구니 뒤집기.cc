#include <iostream>

using namespace std;

int arr[101];

void solution() {
    int N, M, i, j, tmp;

    cin >> N >> M;
    for (i = 1; i <= N; i++)
        arr[i] = i;

    while (M--) {
        cin >> i >> j;
        while (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++, j--;
        }
    }

    for (i = 1; i <= N; i++)
        cout << arr[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}