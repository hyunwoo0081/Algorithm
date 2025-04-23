#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    int arr[3];
    for (int & i : arr) {
        cin >> i;
    }

    sort(arr, arr + 3);
    cout << arr[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}