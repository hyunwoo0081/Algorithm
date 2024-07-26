#include <iostream>

using namespace std;

void solution() {
    int A, B, i = 0;
    int arr[30];

    cin >> A >> B;

    while (A > 0 || B > 0) {
        arr[i++] = A % 10 + B % 10;
        A /= 10;
        B /= 10;
    }

    while (i > 0) {
        cout << arr[--i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}