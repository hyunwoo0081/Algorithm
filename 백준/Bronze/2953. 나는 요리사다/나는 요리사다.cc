#include <iostream>

using namespace std;

void solution() {
    int a, sum, maxIdx, maxSum;

    maxIdx = maxSum = 0;
    for (int i = 0; i < 5; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> a;
            sum += a;
        }
        if (maxSum < sum) {
            maxIdx = i+1;
            maxSum = sum;
        }
    }

    cout << maxIdx << ' ' << maxSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}