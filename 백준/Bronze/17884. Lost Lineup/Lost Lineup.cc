#include <iostream>
#define SIZE 100

using namespace std;

int arr[SIZE];

void solution() {
    int N, a;

    cin >> N;
    arr[0] = 1;
    for (int i = 1; i < N; i++) {
        cin >> a;
        arr[a+1] = i+1;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}