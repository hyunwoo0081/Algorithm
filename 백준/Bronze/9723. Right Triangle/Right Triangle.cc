#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    long long T, arr[3];

    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (auto &c : arr)
            cin >> c;

        sort(arr, arr + 3);

        cout << "Case #" << t << ": " << ((arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}