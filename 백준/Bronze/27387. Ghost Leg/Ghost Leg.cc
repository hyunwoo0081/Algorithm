#include <iostream>
#define SIZE 100

using namespace std;

int arr[SIZE];

void solution() {
    int N, M, a;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> a;

        int tmp = arr[a - 1];
        arr[a - 1] = arr[a];
        arr[a] = tmp;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}