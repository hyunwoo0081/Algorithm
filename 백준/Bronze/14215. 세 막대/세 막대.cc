#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    int arr[3];

    for (auto &a : arr)
        cin >> a;
    sort(arr, arr+3);

    cout << arr[0] + arr[1] + min(arr[0]+arr[1]-1, arr[2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}