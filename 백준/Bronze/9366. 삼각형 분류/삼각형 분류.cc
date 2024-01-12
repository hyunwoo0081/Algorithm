#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    int T;
    int arr[3];

    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int &a : arr)
            cin >> a;
        sort(arr, arr+3);

        cout << "Case #" << t << ": ";
        if (arr[0] + arr[1] <= arr[2])
            cout << "invalid!";
        else if (arr[0] == arr[1] && arr[1] == arr[2])
            cout << "equilateral";
        else if (arr[0] == arr[1] || arr[1] == arr[2])
            cout << "isosceles";
        else
            cout << "scalene";
        cout << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}