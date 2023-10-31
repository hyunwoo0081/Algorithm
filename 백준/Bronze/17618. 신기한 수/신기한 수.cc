#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int N, cnt = 0, tmpN, sum;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        tmpN = i;
        sum = 0;
        while (tmpN > 0) {
            sum += tmpN % 10;
            tmpN /= 10;
        }

        cnt += i % sum == 0;
    }

    cout << cnt;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}