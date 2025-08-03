#include <iostream>
#define SIZE 30

using namespace std;

int arr[SIZE];
void solution() {
    int N, maxN = -987654321;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        maxN = max(maxN, arr[i]);
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] == maxN) {
            cout << (char)('A'+i);
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