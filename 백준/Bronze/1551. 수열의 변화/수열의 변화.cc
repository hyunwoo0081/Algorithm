#include <iostream>
#define SIZE 100

using namespace std;

long long arr[SIZE];
int arrSize;

void zip() {
    arrSize--;
    for (int i = 0; i < arrSize; i++)
        arr[i] = arr[i+1] - arr[i];
}

void solution() {
    int N, K;
    char c;

    cin >> N >> K;
    arrSize = N;
    for (int i = 0; i < N; i++) {
        if (i > 0) cin >> c;
        cin >> arr[i];
    }

    while (K--) zip();

    for (int i = 0; i < arrSize; i++) {
        if (i > 0) cout << ',';
        cout << arr[i];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}