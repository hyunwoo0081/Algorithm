#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll arr[5];

void solution() {
    ll T, sum;

    cin >> T;
    while (T--) {
        for (auto &i : arr)
            cin >> i;
        sort(arr, arr + 5);

        if (arr[3] - arr[1] >= 4) {
            cout << "KIN\n";
            continue;
        }

        sum = 0;
        for (int i = 1; i < 4; i++)
            sum += arr[i];
        cout << sum << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}