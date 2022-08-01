#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    int arr[9], i, j, sum;

    sum = 0;
    for (auto &a: arr) {
        cin >> a;
        sum += a;
    }
    sort(arr, arr+9);

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++)
            if (i != j && arr[i] + arr[j] == sum - 100)
                break;
        if (j != 9) break;
    }
    
    for (int k = 0; k < 9; k++)
        if (k != i && k != j)
            cout << arr[k] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}