#include <iostream>
#define SIZE 1000

using namespace std;
typedef long long ll;

void solution() {
    ll T, N, j, sum, maxNum;
    ll arr[SIZE];

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        j = 0, sum = arr[0];
        maxNum = sum;
        while (++j < N) {
            if (sum <= 0)
                sum = arr[j];
            else
                sum += arr[j];
            maxNum = max(sum, maxNum);
        }

        cout << maxNum << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}