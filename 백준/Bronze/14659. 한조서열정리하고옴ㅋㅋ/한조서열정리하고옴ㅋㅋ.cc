#include <iostream>

using namespace std;

void solution() {
    int N, a, maxNum, count, maxCount;

    maxNum = count = maxCount = 0;

    cin >> N;
    while (N--) {
        cin >> a;

        if (maxNum < a) {
            maxCount = max(maxCount, count);
            count = 0;
            maxNum = a;
        }
        else {
            count++;
        }
    }
    maxCount = max(maxCount, count);

    cout << maxCount;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}