#include <iostream>

using namespace std;

bool possible(bool arr[], int n) {
    if (n < 10)
        return !arr[n];
    else
        return !(arr[n/10] | arr[n%10]);
}

void solution() {
    int T, count;
    int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool arr[10];

    cin >> T;
    while (T--) {
        for (bool & i : arr)
            cin >> i;

        count = 0;
        for (int m = 1; m <= 12; m++) {
            if (possible(arr, m))
                for (int d = 1; d <= days[m-1]; d++)
                    count += possible(arr, d);
        }

        cout << count << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}