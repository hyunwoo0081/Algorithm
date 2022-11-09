#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    int arr[4];

    for (auto &a: arr)
        cin >> a;
    sort(arr, arr+4);

    cout << arr[0]*arr[2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
