#include <iostream>

using namespace std;

void solution() {
    int arr[4][4];
    int tSum, sum;
    bool isSame = true;

    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            cin >> arr[y][x];

    tSum = 0;
    for (int x = 0; x < 4; x++)
        tSum += arr[0][x];

    for (int y = 0; y < 4; y++) {
        sum = 0;
        for (int x = 0; x < 4; x++)
            sum += arr[y][x];

        isSame &= tSum == sum;
    }

    for (int x = 0; x < 4; x++) {
        sum = 0;
        for (int y = 0; y < 4; y++)
            sum += arr[y][x];

        isSame &= tSum == sum;
    }

    cout << (isSame ? "magic" : "not magic");
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}